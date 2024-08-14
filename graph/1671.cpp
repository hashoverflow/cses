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
    int n, m;
    cin >> n >> m;
    vector< vector< pair<int, int> > > adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back(make_pair(v - 1, w));
    }
    vector<long long> dist(n);
    for (int i = 0; i < n; i++) dist[i] = -1;
    priority_queue< pair<long long, int> > q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        pair<long long, int> p = q.top();
        q.pop();
        int x = p.second;
        if (dist[x] != -1) continue;
        dist[x] = -p.first;
        for (int i = 0; i < adj[x].size(); i++) {
            pair<int, int> f = adj[x][i];
            int r = f.first;
            if (dist[r] != -1) continue;
            q.push(make_pair(-(dist[x] + (long long)(f.second)), r));
        }
    }
    for (int i = 0; i < n; i++) cout << dist[i] << " \n"[i == (n - 1)];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}