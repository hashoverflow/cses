// author: hashoverflow
 
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<long long> a;
    long long x = n;
    a.push_back(x);
    while (x != 1) {
        if (x % 2) x = (x * 3) + 1;
        else x /= 2;
        a.push_back(x);
    }
    int s = a.size();
    for (int i = 0; i < s; i++) cout << a[i] << " \n"[i == (s - 1)];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}