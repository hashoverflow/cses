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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> m;
    int r = 0, c = 0;
    long long result = 0;
    for (int l = 0; l < n; l++) {
        while (r < n) {
            if (m.find(a[r]) == m.end()) m[a[r]] = 1;
            else m[a[r]]++;
            if (m[a[r]] == 1) c++;
            if (c > k) {
                m[a[r]]--;
                c--;
                break;
            }
            r++;
        }
        result += r - l;
        m[a[l]]--;
        if (m[a[l]] == 0) c--;
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}