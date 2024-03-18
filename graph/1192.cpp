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
    vector<int> adj[n * m];
    vector<char> grid(n * m);
    int r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[r];
            if (i && grid[r] == grid[r - m] && grid[r] == '.') {
                adj[r].push_back(r - m);
                adj[r - m].push_back(r);
            }
            if (j && grid[r] == grid[r - 1] && grid[r] == '.') {
                adj[r].push_back(r - 1);
                adj[r - 1].push_back(r);
            }
            r++;
        }
    }
    int count = 0;
    bool visited[n * m];
    for (int i = 0; i < (n * m); i++) visited[i] = false;
    for (int i = 0; i < (n * m); i++) {
        if (grid[i] == '#' || visited[i]) continue;
        visited[i] = true;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            int s = adj[x].size();
            for (int j = 0; j < s; j++) {
                int r = adj[x][j];
                if (visited[r]) continue;
                visited[r] = true;
                q.push(r);
            }
        }
        count++;
    }
    cout << count << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}