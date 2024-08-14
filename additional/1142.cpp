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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> l(n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && (a[s.top()] >= a[i])) s.pop();
        l[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop();
    long long result = 0;
    for (int i = (n - 1); i >= 0; i--) {
        while (!s.empty() && (a[s.top()] >= a[i])) s.pop();
        int r = s.empty() ? n : s.top();
        result = max(result, (long long)(r - l[i] - 1) * (long long)(a[i]));
        s.push(i);
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}