// author: hashoverflow
 
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 2 || n == 3) cout << "NO SOLUTION\n";
    else {
        vector<int> a(n);
        int p = 0;
        for (int i = 2; i <= n; i+= 2) {
            a[p] = i;
            p++;
        }
        for (int i = 1; i <= n; i += 2) {
            a[p] = i;
            p++;
        }
        for (int i = 0; i < n; i++) cout << a[i] << (i == (n - 1) ? '\n' : ' ');
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}