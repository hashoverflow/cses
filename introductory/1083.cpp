// author: hashoverflow
 
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<bool> a(n);
    for (int i = 0; i < (n - 1); i++) {
        int x;
        cin >> x;
        a[x - 1] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!a[i]) {
            cout << (i + 1) << '\n';
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}