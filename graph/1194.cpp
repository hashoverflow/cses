// author: hashoverflow

#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<int> dist(n * m);
    for (int i = 0; i < n; i++) cin >> grid[i];
    vector< vector<int> > adj(n * m);
    int r = 0, f;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[r] = n * m;
            if (grid[i][j] == 'M') {
                dist[r] = 0;
                q.push(r);
            }
            if (grid[i][j] == 'A') f = r;
            if (grid[i][j] != '#') {
                if ((i != (n - 1) && (grid[i + 1][j] != '#'))) {
                    adj[r].push_back(r + m);
                    adj[r + m].push_back(r);
                }
                if ((j != (m - 1) && (grid[i][j + 1] != '#'))) {
                    adj[r].push_back(r + 1);
                    adj[r + 1].push_back(r);
                }
            }
            r++;
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < adj[x].size(); i++) {
            int r = adj[x][i];
            if (dist[r] != (n * m)) continue;
            dist[r] = dist[x] + 1;
            q.push(r);
        }
    }
    vector<int> back(n * m), comp(n * m);
    for (int i = 0; i < (n * m); i++) {
        back[i] = -1;
        comp[i] = -1;
    }
    q.push(f);
    comp[f] = 0;
    int c[2] = {f / m, f % m};
    if ((c[0] == 0) || (c[0] == (n - 1)) || (c[1] == 0) || (c[1] == (m - 1))) {
        cout << "YES\n0\n";
        return;
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < adj[x].size(); i++) {
            int r = adj[x][i];
            if (comp[r] != -1) continue;
            comp[r] = comp[x] + 1;
            back[r] = x;
            int c[2] = {r / m, r % m};
            if ((c[0] == 0) || (c[0] == (n - 1)) || (c[1] == 0) || (c[1] == (m - 1))) {
                if (comp[r] < dist[r]) {
                    cout << "YES\n";
                    vector<int> track;
                    while (r != f) {
                        track.push_back(r);
                        r = back[r];
                    }
                    string s;
                    int t = track.size();
                    reverse(track.begin(), track.end());
                    cout << t << '\n';
                    for (int i = 0; i < t; i++) {
                        if ((track[i] - r) == 1) s += 'R';
                        else if ((track[i] - r) == -1) s += 'L';
                        else if ((track[i] - r) == m) s += 'D';
                        else s += 'U';
                        r = track[i];
                    }
                    cout << s << '\n';
                    return;
                }
            }
            q.push(r);
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}