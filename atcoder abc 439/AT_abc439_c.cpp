//
// Created by 陆熠辰 on 26-1-3.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e7+5;
int cnt[MaxN], n;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int y = 1; y * y <= n; y++) {
        int mult_y = y * y;
        for (int x = 1; x < y; x++) {
            int multi = x * x + mult_y;
            if (multi > n) break;
            cnt[multi]++;
        }
    }
    vector<int> ans;
    for (int x = 1; x <= n; x++) {
        if (cnt[x] == 1) {
            ans.push_back(x);
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << " ";
    }
    return 0;
}