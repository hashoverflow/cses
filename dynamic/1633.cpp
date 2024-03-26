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
    vector <int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= 6; j++) {
            if ((i - j) < 0) break;
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    cout << dp[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}