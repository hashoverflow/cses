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
    int n;
    cin >> n;
    vector<int> f(n);
    for (int i = 0; i < n; i++) cin >> f[i];
    int p = 1;
    while (p < n) p *= 2;
    vector<int> a(p * 2);
    for (int i = (p * 2) - 1; i; i--) {
        if (i >= p) {
            if ((i - p) < n) a[i] = 1;
            else a[i] = 0;
        } else a[i] = a[i * 2] + a[(i * 2) + 1];
    }
    for (int i = 0; i < n; i++) {
        int x, r = 1;
        cin >> x;
        while (r < p) {
            if (x <= a[(r * 2)]) r *= 2;
            else {
                x -= a[r * 2];
                r = (r * 2) + 1;
            }
        }
        cout << f[r - p] << " \n"[i == (n - 1)];
        while (r) {
            a[r]--;
            r /= 2;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}