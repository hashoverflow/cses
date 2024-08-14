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
    vector<int> f(n);
    for (int i = 0; i < n; i++) cin >> f[i];
    int p = 1;
    while (p < n) p *= 2;
    vector<long long> a(p * 2, 0);
    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            int l, r, u;
            cin >> l >> r >> u;
            l += p - 1;
            r += p - 1;
            while (l <= r) {
                if (l % 2) {
                    a[l] += u;
                    l++;
                }
                if ((r % 2) == 0) {
                    a[r] += u;
                    r--;
                }
                l /= 2;
                r /= 2;
            }
        } else {
            int y;
            cin >> y;
            long long result = f[y - 1];
            y += p - 1;
            while (y) {
                result += a[y];
                y /= 2;
            }
            cout << result << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}