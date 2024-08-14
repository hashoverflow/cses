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

int search(int a, vector<int>& u) {
    int l = 0, r = u.size() - 1;
    while (l < r) {
        int c = (l + r + 1) / 2;
        if (a < u[c]) r = c - 1;
        else l = c;
    }
    return l;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> f(n);
    for (int i = 0; i < n; i++) cin >> f[i];
    vector< pair< char, pair<int, int> > > s;
    vector<int> v, u;
    v.push_back(1);
    for (int i = 0; i < q; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == '?') {
            v.push_back(a);
            v.push_back(b + 1);
        }
        s.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(v.begin(), v.end());
    map<int, int> m;
    int d = 0;
    for (int i = 0; i < v.size(); i++) {
        if ((i == 0) || (v[i] != v[i - 1])) {
            m[v[i]] = d;
            u.push_back(v[i]);
            d++;
        }
    }
    int p = 1;
    while (p < d) p *= 2;
    vector<int> a(p * 2, 0);
    for (int i = 0; i < n; i++) {
        int x = search(f[i], u) + p;
        while (x) {
            a[x]++;
            x /= 2;
        }
    }
    for (int i = 0; i < q; i++) {
        char c = s[i].first;
        int l = s[i].second.first, r = s[i].second.second;
        if (c == '?') {
            l = p + m[l];
            r = p + m[r + 1] - 1;
            int result = 0;
            while (l <= r) {
                if (l % 2) {
                    result += a[l];
                    l++;
                }
                if ((r % 2) == 0) {
                    result += a[r];
                    r--;
                }
                l /= 2;
                r /= 2;
            }
            cout << result << '\n';
        } else {
            int x = search(f[l - 1], u);
            x += p;
            while (x) {
                a[x]--;
                x /= 2;
            }
            f[l - 1] = r;
            x = p + search(r, u);
            while (x) {
                a[x]++;
                x /= 2;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}