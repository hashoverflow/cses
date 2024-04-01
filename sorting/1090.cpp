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
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    sort(w.begin(), w.end());
    int l = 0, r = n - 1, result = 0;
    while (l <= r) {
        if ((l < r) && (w[l] + w[r]) <= x) {
            l++;
            r--;
            result++;
        } else {
            r--;
            result++;
        }
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}