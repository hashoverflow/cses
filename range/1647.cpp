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

const int MAX = 1000000000;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> f(n);
    for (int i = 0; i < n; i++) cin >> f[i];
    int p = 1;
    while (p < n) p *= 2;
    vector<int> a(p * 2);
    for (int i = (p * 2) - 1; i; i--) {
        if (i >= p) {
            if ((i - p) < n) a[i] = f[i - p];
            else a[i] = MAX;
        } else a[i] = min(a[i * 2], a[(i * 2) + 1]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l += p - 1;
        r += p - 1;
        int result = MAX;
        while (l <= r) {
            if (l % 2) {
                result = min(result, a[l]);
                l++;
            }
            if ((r % 2) == 0) {
                result = min(result, a[r]);
                r--;
            }
            l /= 2;
            r /= 2;
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