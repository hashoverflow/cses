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
    int n, q;
    cin >> n >> q;
    vector< vector<int> > dp;
    for (int i = 0; i < 30; i++) {
        vector<int> row(n);
        if (i == 0) {
            for (int j = 0; j < n; j++) {
                cin >> row[j];
                row[j]--;
            }
        } else {
            for (int j = 0; j < n; j++) row[j] = dp[i - 1][dp[i - 1][j]];
        }
        dp.push_back(row);
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        x--;
        for (int i = 0; i < 30; i++) {
            int d = k % 2;
            if (d) x = dp[i][x];
            k /= 2;
        }
        cout << (x + 1) << '\n';
    }
}

void tsolve() {
    int t;
    cin >> t;
    while (t--) solve();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}