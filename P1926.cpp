//
// Created by 陆熠辰 on 26-1-22.
//
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int n, m, k, r;
int time_ti[15], time_homework[15], score[15];
int dp[1005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k >> r;
    for (int i = 1; i <= n; i++) cin >> time_ti[i];
    for (int i = 1; i <= m; i++) cin >> time_homework[i];
    for (int i = 1; i <= m; i++) cin >> score[i];
    sort(time_ti + 1, time_ti + n + 1);
    for (int i = 0; i <= 1000; i++) dp[i] = 1e9;
    for (int i = 1; i <= m; i++) {
        for (int j = 1000; j >= score[i]; j--) {
            dp[j] = min(dp[j], dp[j - score[i]] + time_homework[i]);
        }
    }
    int minn = 1e9;
    for (int j = k; j <= 1000; j++) minn = min(minn, dp[j]);
    r -= minn;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        if (r >= time_ti[i]) {
            r -= time_ti[i];
            s++;
        }
        else break;
    }
    cout << s << endl;
    return 0;
}