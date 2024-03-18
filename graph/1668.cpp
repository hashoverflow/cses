// author: hashoverflow
 
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vector<bool> flag(n), color(n);
    for (int i = 0; i < n; i++) flag[i] = (color[i] = false);
    for (int i = 0; i < n; i++) {
        if (flag[i]) continue;
        flag[i] = true;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            int s = adj[x].size();
            for (int j = 0; j < s; j++) {
                int r = adj[x][j];
                if (flag[r]) {
                    if (color[x] == color[r]) {
                        cout << "IMPOSSIBLE\n";
                        return;
                    } else continue;
                }
                flag[r] = true;
                color[r] = !color[x];
                q.push(r);
            }
        }
    }
    for (int i = 0; i < n; i++) cout << (color[i] ? 2 : 1) << (i == n - 1 ? '\n' : ' ');
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}