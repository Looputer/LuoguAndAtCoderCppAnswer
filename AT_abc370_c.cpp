//
// Created by 陆熠辰 on 26-2-28.
//
#include <iostream>
#include <vector>
using namespace std;

string s, t;
vector<string> ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t;
    int len = s.length();
    s = " " + s;
    t = " " + t;
    for (int i = 1; i <= len; i++) {
        if (s[i] > t[i]) {
            s[i] = t[i];
            ans.push_back(s);
        }
    }
    for (int i = len; i >= 1; i--) {
        if (s[i] < t[i]) {
            s[i] = t[i];
            ans.push_back(s);
        }
    }
    cout << ans.size() << endl;
    for (auto str : ans) {
        cout << str << endl;
    }
    return 0;
}