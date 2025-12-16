//
// Created by 陆熠辰 on 25-12-15.
//
#include <iostream>
#include <string>
using namespace std;

int n;
string s, ans;

int main() {
    cin >> n >> s;
    int l = n - s.length();
    for (int i = 1; i <= l; i++) ans += 'o';
    ans += s;
    cout << ans << endl;
}