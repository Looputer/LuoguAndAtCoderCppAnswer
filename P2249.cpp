//
// Created by 陆熠辰 on 26-3-1.
//
#include <iostream>
using namespace std;

const int MaxN = 1e6+5;
int a[MaxN], n, m;

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int find;
        cin >> find;
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[mid] >= find) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        if (a[l] == find) cout << l << " ";
        else cout << -1 << " ";
    }
}