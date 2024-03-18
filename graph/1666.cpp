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
    vector<int> root;
    vector<bool> flag(n);
    for (int i = 0; i < n; i++) flag[i] = false;
    for (int i = 0; i < n; i++) {
        if (flag[i]) continue;
        flag[i] = true;
        queue<int> q;
        q.push(i);
        root.push_back(i + 1);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            int s = adj[x].size();
            for (int j = 0; j < s; j++) {
                int r = adj[x][j];
                if (flag[r]) continue;
                flag[r] = true;
                q.push(r);
            }
        }
    }
    int s = root.size();
    cout << (s - 1) << '\n';
    for (int i = 1; i < s; i++) cout << root[i - 1] << ' ' << root[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}