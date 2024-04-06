// author: hashoverflow
 
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if ((n % 4 == 1) || (n % 4 == 2)) cout << "NO\n";
    else {
        cout << "YES\n";
        vector<bool> split(n);
        for (int i = 0; i < n; i++) split[i] = false;
        for (int i = 1; i <= ((n + 1) / 4); i++) {
            split[i - 1] = true;
            if ((i == 1) && (n % 2)) split[n / 2] = true;
            else if (n % 2) split[n - i + 1] = true;
            else split[n - i] = true;
        }
        int x = 0;
        for (int i = 0; i < n; i++) x += split[i] ? 1 : 0;
        cout << x << '\n';
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (split[i]) {
                j++;
                cout << (i + 1) << ((j == x) ? '\n' : ' ');
            }
        }
        cout << (n - x) << '\n';
        for (int i = 0; i < n; i++) {
            if (!split[i]) {
                j++;
                cout << (i + 1) << ((j == n) ? '\n' : ' ');
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