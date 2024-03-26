// author: hashoverflow
 
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<int> dp(x + 1);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        dp[i] = x + 1;
        for (int j = 0; j < n; j++) {
            if ((i - c[j]) >= 0) dp[i] = min(dp[i], dp[i - c[j]] + 1);
        }
    }
    if (dp[x] > x) cout << -1 << '\n';
    else cout << dp[x] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}