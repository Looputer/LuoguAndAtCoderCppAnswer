//
// Created by 陆熠辰 on 25-11-9.
//
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int x, int y) {
    return x > y;
}
int a[105], s[15][15];
int n, m;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    int pchan = a[1];
    sort(a + 1, a + n + 1, cmp);
    pair<int, int> p = make_pair(1, 1);
    for (int i = 1; i <= n * m; i++) {
        if (p.first == n) {
            if (p.second == m) {
                break;
            }
            p.second++;
            s[p.first][p.second] = a[i];
            continue;
        }
        p.first++;
        s[p.first][p.second] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == pchan) {
                cout << i << " " << j << endl;
            }
        }
    }
}