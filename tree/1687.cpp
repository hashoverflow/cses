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

void dfs(int r, int f, int p, vector<int>& s, vector< vector<int> >& adj, vector< vector<int> >& bin) {
    bin[r][f] = (s.size() >= p) ? s[s.size() - p] : -1;
    s.push_back(r);
    for (int i = 0; i < adj[r].size(); i++) dfs(adj[r][i], f, p, s, adj, bin);
    s.pop_back();
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector< vector<int> > adj(n), bin;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        adj[x - 1].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < 18; j++) row.push_back(-1);
        bin.push_back(row);
    }
    int p = 1;
    for (int i = 0; i < 18; i++) {
        vector<int> s;
        dfs(0, i, p, s, adj, bin);
        p *= 2;
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        x--;
        for (int i = 0; i < 18; i++) {
            if (k % 2) x = bin[x][i];
            if (x == -1) break;
            k /= 2;
        }
        cout << ((x == -1) ? -1 : (x + 1)) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}