// author: hashoverflow
 
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    int p = 1;
    while (n--) p = (p * 2) % MOD;
    cout << p << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}