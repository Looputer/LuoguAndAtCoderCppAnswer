//
// Created by 陆熠辰 on 25-12-23.
//
#include <iostream>
#include <set>
#include <string>
#define int long long
#define Aishiteru ios::sync_with_stdio(0);
#define Tousei cin.tie(0);
using namespace std;

const int MaxN = 1e5+5;
string s;
int n;
int v[MaxN], dp[MaxN];

signed main() {
    Aishiteru Tousei
    cin >> n;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    dp[0] = dp[1];
    for (int i = 1; i < n; i++) {
        set<char> st;
        dp[i] = dp[i-1] + v[i];
        st.insert(s[i]);
        for (int j = i - 1;j >= 0;j--) {
            if (st.count(s[j])) break;
            st.insert(s[j]);
            dp[i] = max(dp[i], dp[j-1] + v[i-j+1]);
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}