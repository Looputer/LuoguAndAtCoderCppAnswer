//
// Created by 陆熠辰 on 25-11-9.
//
#include <iostream>
#define int long long
using namespace std;
const int MaxN = 1e6+5;
int a[MaxN], s[MaxN];
bool isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2;i * i <= n;i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

signed main() {
    int n;
    cin >> n;
    int maxn = 1e6;
    for (int i = 1;i <= maxn;i++) {
        a[i] = isPrime(i);
        s[i] = s[i-1] + a[i];
    }
    while (n--) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
}