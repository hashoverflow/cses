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

void dfs(int r, vector< vector<int> >& adj, vector<int>& dp, vector<bool>& flag) {
    flag[r] = true;
    dp[r] = 0;
    for (int i = 0; i < adj[r].size(); i++) {
        int x = adj[r][i];
        if (flag[x]) continue;
        dfs(x, adj, dp, flag);
        dp[r] += dp[x] + 1;
    }
    flag[r] = false;
}

void solve() {
    int n;
    cin >> n;
    vector< vector<int> > adj(n);
    for (int i = 1; i < n; i++) {
        int v;
        cin >> v;
        adj[i].push_back(v - 1);
        adj[v - 1].push_back(i);
    }
    vector<int> dp(n);
    vector<bool> flag(n);
    for (int i = 0; i < n; i++) flag[i] = false;
    dfs(0, adj, dp, flag);
    for (int i = 0; i < n; i++) cout << dp[i] << " \n"[i == (n - 1)];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}