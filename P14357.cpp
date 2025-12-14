//
// Created by 陆熠辰 on 25-11-9.
//
#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 1e6+5;
int a[MaxN];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0;i < s.size();i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            a[cnt] = s[i] - '0';
            cnt++;
        }
    }
    string ans;
    sort(a, a+cnt, cmp);
    for (int i = 0;i < cnt;i++) {
        ans += '0' + a[i];
    }
    cout << ans << endl;
    return 0;
}