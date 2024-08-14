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

void dfs(int x, int y, vector< vector<int> >& adj, vector<long long>& a, vector<int>& b) {
    a[x] = 0;
    b[x] = 1;
    for (int i = 0; i < adj[x].size(); i++) {
        int r = adj[x][i];
        if (r == y) continue;
        dfs(r, x, adj, a, b);
        a[x] += a[r] + (long long)(b[r]);
        b[x] += b[r];
    }
}

void update(int x, int y, int n, vector< vector<int> >& adj, vector<long long>& a, vector<int>& b) {
    for (int i = 0; i < adj[x].size(); i++) {
        int r = adj[x][i];
        if (r == y) continue;
        a[r] = a[x] + (long long)(n - b[r] * 2);
        update(r, x, n, adj, a, b);
    }
}

void solve() {
    int n;
    cin >> n;
    vector< vector<int> > adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vector<long long> a(n);
    vector<int> b(n);
    dfs(0, -1, adj, a, b);
    update(0, -1, n, adj, a, b);
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == (n - 1)];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}