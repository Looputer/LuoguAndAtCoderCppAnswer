//
// Created by 陆熠辰 on 26-1-3.
//
#include <iostream>
#define int long long
using namespace std;

int used[2030];
int split(int n) {
    int ans = 0;
    while (n) {
        int mod = n % 10;
        ans += mod * mod;
        n /= 10;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (true) {
        if (n == 1) {
            cout << "Yes" << endl;
            return 0;
        }
        if (used[n]) {
            cout << "No" << endl;
            return 0;
        }
        used[n] = 1;
        n = split(n);
    }
}