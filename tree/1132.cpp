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
    int u;
    queue<int> q;
    q.push(0);
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
    int v;
    q.push(u);
    vector<int> dist(n), result(n);
    dist[u] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        result[x] = dist[x];
        for (int i = 0; i < adj[x].size(); i++) {
            int r = adj[x][i];
            if (flag[r]) continue;
            flag[r] = true;
            q.push(r);
            dist[r] = dist[x] + 1;
        }
        v = x;
    }
    for (int i = 0; i < n; i++) flag[i] = false;
    flag[v] = true;
    q.push(v);
    dist[v] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        result[x] = max(result[x], dist[x]);
        for (int i = 0; i < adj[x].size(); i++) {
            int r = adj[x][i];
            if (flag[r]) continue;
            flag[r] = true;
            q.push(r);
            dist[r] = dist[x] + 1;
        }
        v = x;
    }
    for (int i = 0; i < n; i++) cout << result[i] << " \n"[i == (n - 1)];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}