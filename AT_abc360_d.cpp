//
// Created by 陆熠辰 on 2026/7/26.
//
#include <iostream>
#include <string>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
int n, T;
string s;
vector<int> pos, neg;

int bs1(int L) {
    int l = 0, r = neg.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (neg[mid] >= L) r = mid;
        else l = mid + 1;
    }
    if (neg[l] < L) return -1;
    return l;
}

int bs2(int R) {
    int l = 0, r = neg.size() - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (neg[mid] <= R) l = mid;
        else r = mid - 1;
    }
    if (neg[l] > R) return -1;
    return l;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> T;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        int posi;
        cin >> posi;
        if (s[i] == '0') neg.push_back(posi);
        else pos.push_back(posi);
    }
    sort(neg.begin(), neg.end());
    int ans = 0;
    for (auto x : pos) {
        int L = bs1(x);
        int R = bs2(x+2*T);
        if (L == -1 || R == -1) continue;
        ans += R - L + 1;
    }
    cout << ans << endl;
}