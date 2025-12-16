//
// Created by 陆熠辰 on 25-12-15.
//
#include <iostream>
#include <set>
#define int long long
using namespace std;

int n, m, ans;
const int INF = 1e10 + 100;

signed main() {
    cin >> n >> m;
    set<int> used;
    for (int i = 1;i <= m;i++) {
        int flag = true;
        int x, y;
        cin >> x >> y;
        int b[4][2] = {
            {x, y},
            {x + 1, y},
            {x, y + 1},
            {x + 1, y + 1}
        };
        for (int i = 0;i < 4;i++) {
            int key = b[i][0] * INF + b[i][1];
            if (used.count(key)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans++;
            for (int i = 0;i < 4;i++) {
                int key = b[i][0] * INF + b[i][1];
                used.insert(key);
            }
        }
    }
    cout << ans << endl;
    return 0;
}