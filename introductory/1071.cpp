// author: hashoverflow
 
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        long long f = max(x, y);
        long long l = (f - 1) * (f - 1), r = f * f, result;
        if ((l % 2 == 1)) {
            if (y == f) result = l + x;
            else result = r - (y - 1);
        } else {
            if (x == f) result = l + y;
            else result = r - (x - 1);
        }
        cout << result << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}