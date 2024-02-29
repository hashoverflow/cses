// author: hashoverflow
 
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int l = 0, r, result = 0;
    while (l < n) {
        r = l;
        while ((r + 1) < n && s[r + 1] == s[l]) r++;
        result = max(result, r - l + 1);
        l = r + 1;
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}