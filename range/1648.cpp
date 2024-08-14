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
    vector<long long> a(p * 2);
    for (int i = (p * 2) - 1; i; i--) {
        if (i >= p) {
            if ((i - p) < n) a[i] = f[i - p];
            else a[i] = 0;
        } else a[i] = a[i * 2] + a[(i * 2) + 1];
    }
    while (q--) {
        int k, x, y;
        cin >> k >> x >> y;
        if (k == 1) {
            int d = y - f[x - 1];
            f[x - 1] = y;
            x += p - 1;
            while (x) {
                a[x] += d;
                x /= 2;
            }
        } else {
            long long sum = 0;
            x += p - 1;
            y += p - 1;
            while (x <= y) {
                if (x % 2) {
                    sum += a[x];
                    x++;
                }
                if ((y % 2) == 0) {
                    sum += a[y];
                    y--;
                }
                x /= 2;
                y /= 2;
            }
            cout << sum << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}