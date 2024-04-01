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
    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<int> dp(x + 1);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) dp[i] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= h[i]; j--) {
            if (dp[j - h[i]] != -1) dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }
    int result = 0;
    for (int i = 0; i <= x; i++) result = max(result, dp[i]);
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}