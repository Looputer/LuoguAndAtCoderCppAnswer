//
// Created by 陆熠辰 on 26-3-1.
//

#include <iostream>
#include <string>
using namespace std;

string s;

signed main() {
    cin >> s;
    s = " " + s;
    int l = 1, r = s.length();
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (s[mid] == '1') l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}