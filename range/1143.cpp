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
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    int p = 1;
    while (p < n) p *= 2;
    vector<int> a(p * 2);
    for (int i = (p * 2) - 1; i; i--) {
        if (i >= p) {
            if ((i - p) >= n) a[i] = 0;
            else a[i] = x[i - p];
        } else a[i] = max(a[i * 2], a[(i * 2) + 1]);
    }
    while (m--) {
        int y, q;
        cin >> y;
        if (y > a[1]) q = 0;
        else {
            int l = 0, r = n - 1;
            while (l < r) {
                int c = (l + r) / 2;
                int g = p, h = p + c, maxi = 0;
                while (g <= h) {
                    if (g % 2) {
                        maxi = max(maxi, a[g]);
                        g++;
                    }
                    if ((h % 2) == 0) {
                        maxi = max(maxi, a[h]);
                        h--;
                    }
                    g /= 2;
                    h /= 2;
                }
                if (maxi >= y) r = c;
                else l = c + 1;
            }
            q = l + 1;
        }
        cout << q << " \n"[m == 0];
        if (q) {
            int g = p + q - 1;
            a[g] -= y;
            while (g) {
                if (g < p) a[g] = max(a[g * 2], a[(g * 2) + 1]);
                g /= 2;
            }
        }
    }
}

void tsolve() {
    int t;
    cin >> t;
    while (t--) solve();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}