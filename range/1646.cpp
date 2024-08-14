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
    vector<long long> a(n + 1);
    a[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i + 1];
        a[i + 1] += a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (a[r] - a[l - 1]) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}