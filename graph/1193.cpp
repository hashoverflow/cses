// author: hashoverflow
 
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<char> grid(n * m);
    for (int i = 0; i < (n * m); i++) cin >> grid[i];
    queue<int> q;
    vector<int> back(n * m);
    for (int i = 0; i < (n * m); i++) {
        back[i] = -1;
        if (grid[i] == 'A') {
            q.push(i);
            back[i] = n * m;
        }
    }
    int point = -1;
    while (!q.empty()) {
        int x = q.front();
        if (grid[x] == 'B') {
            point = x;
            break;
        }
        q.pop();
        if (x % m != 0 && grid[x - 1] != '#' && back[x - 1] == -1) {
            q.push(x - 1);
            back[x - 1] = x;
        }
        if ((x + 1) % m != 0 && grid[x + 1] != '#' && back[x + 1] == -1) {
            q.push(x + 1);
            back[x + 1] = x;
        }
        if ((x - m) >= 0 && grid[x - m] != '#' && back[x - m] == -1) {
            q.push(x - m);
            back[x - m] = x;
        }
        if ((x + m) < (n * m) && grid[x + m] != '#' && back[x + m] == -1) {
            q.push(x + m);
            back[x + m] = x;
        }
    }
    if (point == -1) cout << "NO\n";
    else {
        cout << "YES\n";
        vector<int> path;
        path.push_back(point);
        while (grid[point] != 'A') {
            point = back[point];
            path.push_back(point);
        }
        int s = path.size();
        string dir;
        for (int i = s - 2; i >= 0; i--) {
            if (path[i] - path[i + 1] == -1 && m != 1) dir += 'L';
            else if (path[i] - path[i + 1] == 1 && m != 1) dir += 'R';
            else if (path[i] - path[i + 1] == m) dir += 'D';
            else dir += 'U';
        }
        cout << dir.length() << '\n';
        cout << dir << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}