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

void dfs(int x, int f, int p, vector< vector<int> >& adj, vector< vector<int> >& anc, vector<int>& s) {
    if (p <= s.size()) anc[x][f] = s[s.size() - p];
    s.push_back(x);
    for (int i = 0; i < adj[x].size(); i++) dfs(adj[x][i], f, p, adj, anc, s);
    s.pop_back();
}

void calc(int x, int d, vector< vector<int> >& adj, vector<int>& depth) {
    depth[x] = d;
    for (int i = 0; i < adj[x].size(); i++) calc(adj[x][i], d + 1, adj, depth);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector< vector<int> > adj(n);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        adj[x - 1].push_back(i);
    }
    vector< vector<int> > anc;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < 18; j++) row.push_back(-1);
        anc.push_back(row);
    }
    int p = 1;
    for (int i = 0; i < 18; i++) {
        vector<int> s;
        dfs(0, i, p, adj, anc, s);
        p *= 2;
    }
    vector<int> depth(n);
    calc(0, 0, adj, depth);
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int l = 0, r = min(depth[a], depth[b]);
        while (l < r) {
            int c = (l + r + 1) / 2;
            int g = c - depth[a], h = a;
            for (int i = 0; i < 18; i++) {
                if (g % 2) h = anc[h][i];
                g /= 2;
            }
            int v = h;
            g = c - depth[b];
            h = b;
            for (int i = 0; i < 18; i++) {
                if (g % 2) h = anc[h][i];
                g /= 2;
            }
            if (h == v) l = c;
            else r = c - 1;
        }
        int g = l - depth[a], h = a;
        for (int i = 0; i < 18; i++) {
            if (g % 2) h = anc[h][i];
            g /= 2;
        }
        cout << (h + 1) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}