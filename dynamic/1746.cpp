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

const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector< vector<long long> > dp;
    for (int i = 0; i < n; i++) {
        vector<long long> row;
        if (i == 0) {
            if (a[i] == 0) {
                for (int j = 0; j < m; j++) row.push_back(1);
            } else {
                for (int j = 0; j < m; j++) row.push_back((a[i] == (j + 1)) ? 1 : 0);
            }
        } else {
            for (int j = 0; j < m; j++) {
                if (a[i] && (a[i] != (j + 1))) {
                    row.push_back(0);
                    continue;
                }
                long long sum = dp[i - 1][j];
                if (j != 0) sum = (sum + dp[i - 1][j - 1]) % MOD;
                if (j != (m - 1)) sum = (sum + dp[i - 1][j + 1]) % MOD;
                row.push_back(sum);
            }
        }
        dp.push_back(row);
    }
    if (a[n - 1] == 0) {
        long long result = 0;
        for (int i = 0; i < m; i++) result = (result + dp[n - 1][i]) % MOD;
        cout << result << '\n';
    } else cout << dp[n - 1][a[n - 1] - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}