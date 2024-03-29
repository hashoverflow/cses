// author: hashoverflow
 
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    vector<int> dp(n * n);
    int r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[r] = (i + j == 0) ? 1 : 0;
            if (i) dp[r] = (dp[r] + dp[r - n]) % MOD;
            if (j) dp[r] = (dp[r] + dp[r - 1]) % MOD;
            if (grid[i][j] == '*') dp[r] = 0;
            r++;
        }
    }
    cout << dp[(n * n) - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}