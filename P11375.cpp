//
// Created by 陆熠辰 on 26-3-10.
//
#include <iostream>
#define int long long
using namespace std;

int n, s;
string str;

signed main() {
    cin >> n >> s >> str;
    string stack;
    for (auto ch : str) {
        if (ch == 'U') {
            if (!stack.empty()) stack.pop_back();
            else if (s != 1) s /= 2;
        }
        else {
            stack.push_back(ch);
        }
    }
    for (auto ch : stack) {
        if (ch == 'L') s *= 2;
        else s = s * 2 + 1;
    }
    cout << s << endl;
}