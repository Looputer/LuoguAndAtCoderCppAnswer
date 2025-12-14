//
// Created by 陆熠辰 on 25-12-9.
//
#include <iostream>
using namespace std;
const int MaxN = 5 * 1e5 + 5;
int n, a[MaxN], maxn = 1;
int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n && i <= maxn;i++) {
        int idx = i + a[i] - 1;
        maxn = max(maxn, idx);
        if (maxn >= n) {
            cout << n << endl;
            return 0;
        }
    }
    cout << maxn << endl;
    return 0;
}