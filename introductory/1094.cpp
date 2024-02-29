// author: hashoverflow
 
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long result = 0;
    for (int i = 0; i < (n - 1); i++) {
        result += max(0, a[i] - a[i + 1]);
        a[i + 1] = max(a[i + 1], a[i]);
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}