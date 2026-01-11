//
// Created by 陆熠辰 on 26-1-2.
//
#include <iostream>
#include <string>
#define int long long
using namespace std;

const int MaxN = 1e3+5;
int dp[MaxN][MaxN];
string a, b;
int lena, lenb;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    lena = a.length();
    lenb = b.length();
    a = " " + a;
    b = " " + b;
    for (int i = 1; i <= lena; i++) {
        for (int j = 1; j <= lenb; j++) {
            if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[lena][lenb] << endl;
    return 0;
}