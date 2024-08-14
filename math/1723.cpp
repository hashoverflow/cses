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

const int MOD = 1000000007;

void mul(int n, vector< vector<int> >& a, vector< vector<int> >& b) {
    vector< vector<int> > result;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            long long elem = 0;
            for (int k = 0; k < n; k++) elem = (elem + ((long long)(a[i][k]) * (long long)(b[k][j])) % MOD) % MOD;
            row.push_back((int)(elem));
        }
        result.push_back(row);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) a[i][j] = result[i][j];
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector< vector<int> > a, b;
    for (int i = 0; i < n; i++) {
        vector<int> row, dum;
        for (int j = 0; j < n; j++) {
            row.push_back(0);
            dum.push_back((i == j) ? 1 : 0);
        }
        a.push_back(row);
        b.push_back(dum);
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x - 1][y - 1]++;
    }
    while (k) {
        int d = k % 2;
        if (d) mul(n, b, a);
        mul(n, a, a);
        k /= 2;
    }
    cout << b[0][n - 1] << '\n';
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