// author: hashoverflow

#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

void dfs(int r, vector< vector<int> >& adj, vector<bool>& flag, vector<int>& a, vector<int>& b) {
    flag[r] = true;
    a[r] = 0;
    int maxi = 0;
    for (int i = 0; i < adj[r].size(); i++) {
        int x = adj[r][i];
        if (flag[x]) continue;
        dfs(x, adj, flag, a, b);
        a[r] += max(a[x], b[x]);
        maxi = max(maxi, a[x] - max(a[x], b[x]) + 1);
    }
    b[r] = a[r] + maxi;
    flag[r] = false;
}

void solve() {
    int n;
    cin >> n;
    vector< vector<int> > adj(n);
    vector<int> a(n), b(n);
    vector<bool> flag(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
        flag[i] = false;
    }
    dfs(0, adj, flag, a, b);
    cout << max(a[0], b[0]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}