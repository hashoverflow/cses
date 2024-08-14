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
    vector<int> row(m, 0);
    long long result = 0;
    for (int i = 0; i < n; i++) {
        string f;
        cin >> f;
        for (int j = 0; j < m; j++) row[j] = (f[j] == '.') ? (row[j] + 1) : 0;
        stack<int> s;
        vector<int> l(m);
        for (int j = 0; j < m; j++) {
            while (!s.empty() && (row[s.top()] >= row[j])) s.pop();
            l[j] = s.empty() ? -1 : s.top();
            s.push(j);
        }
        while (!s.empty()) s.pop();
        for (int j = (m - 1); j >= 0; j--) {
            while (!s.empty() && (row[s.top()] >= row[j])) s.pop();
            int r = s.empty() ? m : s.top();
            s.push(j);
            result = max(result, (long long)(r - l[j] - 1) * (long long)(row[j]));
        }
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}