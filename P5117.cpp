//
// Created by 陆熠辰 on 25-11-16.
//
#include <iostream>
using namespace std;

int c[1005];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int s, t, b;
        cin >> s >> t >> b;
        c[s] += b;
        c[t+1] -= b;
    }
    int ans = -1e9, sum = 0;
    for (int i = 1;i <= 1000;i++) {
        sum += c[i];
        if (sum > ans) ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}