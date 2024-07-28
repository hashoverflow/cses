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
    vector<bool> flag(n);
    for (int i = 0; i < n; i++) flag[i] = false;
    flag[0] = true;
    queue<int> q;
    q.push(0);
    int u;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < adj[x].size(); i++) {
            int r = adj[x][i];
            if (flag[r]) continue;
            flag[r] = true;
            q.push(r);
        }
        u = x;
    }
    for (int i = 0; i < n; i++) flag[i] = false;
    flag[u] = true;
    vector<int> dist(n);
    dist[u] = 0;
    q.push(u);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < adj[x].size(); i++) {
            int r = adj[x][i];
            if (flag[r]) continue;
            flag[r] = true;
            dist[r] = dist[x] + 1;
            q.push(r);
        }
        u = x;
    }
    cout << dist[u] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}