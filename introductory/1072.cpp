// author: hashoverflow
 
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        long long result = (i * i) * ((i * i) - 1) / 2;
        result -= 4 * (i - 1) * (i - 2);
        cout << result << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}