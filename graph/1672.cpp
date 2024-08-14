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
    int n, m, q;
    cin >> n >> m >> q;
    vector< vector<long long> > grid;
    for (int i = 0; i < n; i++) {
        vector<long long> row;
        for (int j = 0; j < n; j++) row.push_back((i == j) ? 0 : -1);
        grid.push_back(row);
    }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (grid[a - 1][b - 1] == -1) {
            grid[a - 1][b - 1] = c;
            grid[b - 1][a - 1] = c;
        } else {
            grid[a - 1][b - 1] = min(grid[a - 1][b - 1], (long long)(c));
            grid[b - 1][a - 1] = min(grid[b - 1][a - 1], (long long)(c));
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][k] == -1) continue;
                if (grid[k][j] == -1) continue;
                if (((grid[i][k] + grid[k][j]) < grid[i][j]) || (grid[i][j] == -1)) grid[i][j] = grid[i][k] + grid[k][j];
            }
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << grid[u - 1][v - 1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}