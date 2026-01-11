//
// Created by 陆熠辰 on 26-1-3.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#define int long long
using namespace std;

int n;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> v(n);
    for (auto c : v) cin >> c;
    unordered_map<int, int> l, r;
    for (auto c : v) r[c]++;
    int ans = 0;
    for (int j = 0;j < n;j++) {
        r[v[j]]--;
        if (v[j] % 5 == 0) {
            int t = v[j] / 5;
            int seven = 7 * t;
            int three = 3 * t;
            int cnt_left = l[seven] * l[three];
            int cnt_right = r[seven] * r[three];
            ans += cnt_left + cnt_right;
        }
        l[v[j]]++;
    }
    cout << ans << endl;
    return 0;
}