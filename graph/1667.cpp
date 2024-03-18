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
    vector<int> back(n);
    for (int i = 0; i < n; i++) back[i] = -1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int x = q.front();
        if (x == (n - 1)) break;
        q.pop();
        int s = adj[x].size();
        for (int i = 0; i < s; i++) {
            int r = adj[x][i];
            if (back[r] != -1) continue;
            back[r] = x;
            q.push(r);
        }
    }
    if (back[n - 1] == -1) cout << "IMPOSSIBLE\n";
    else {
        vector<int> path;
        int node = n - 1;
        path.push_back(node + 1);
        while (node != 0) {
            node = back[node];
            path.push_back(node + 1);
        }
        int s = path.size();
        cout << s << '\n';
        for (int i = (s - 1); i >= 0; i--) cout << path[i] << ((i == 0) ? '\n' : ' ');
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}