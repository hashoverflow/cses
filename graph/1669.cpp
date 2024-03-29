// author: hashoverflow
 
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> adj[100000], back(100000);
vector<bool> flag(100000);

int dfs(int x) {
    int s = adj[x].size();
    for (int i = 0; i < s; i++) {
        int r = adj[x][i];
        if (back[x] == r) continue;
        back[r] = x;
        if (flag[r]) return r;
        flag[r] = true;
        int c = dfs(r);
        if (c != -1) return c;
    }
    return -1;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    for (int i = 0; i < n; i++) {
        flag[i] = false;
        back[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        if (flag[i]) continue;
        flag[i] = true;
        int c = dfs(i);
        if (c == -1) continue;
        vector<int> path;
        path.push_back(c);
        int d = back[c];
        while (d != c) {
            path.push_back(d);
            d = back[d];
        }
        path.push_back(c);
        int s = path.size();
        cout << s << '\n';
        for (int i = 0; i < s; i++) cout << (path[i] + 1) << (i == (s - 1) ? '\n' : ' ');
        return;
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}