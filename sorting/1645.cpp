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
    vector<int> a;
    a.push_back(0);
    stack<int> s;
    s.push(0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
        while (!s.empty() && (a[s.top()] >= a[i])) s.pop();
        cout << s.top() << " \n"[i == n];
        s.push(i);
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