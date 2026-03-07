//
// Created by 陆熠辰 on 26-3-7.
//
#include <iostream>
using namespace std;

vector<string> gray(int n) {
    if (n == 1) return {"0", "1"};
    vector<string> prev = gray(n - 1);
    vector<string> res;
    for (auto s : prev) {
        res.push_back("0" + s);
    }
    reverse(prev.begin(), prev.end());
    for (auto s : prev) {
        res.push_back("1" + s);
    }
    return res;
}
signed main() {
    int n;
    cin>>n;
    int tol = 1 << n;
    cout << "十进制：" << endl;
    for (int i = 0; i < tol; i++) {
        int gray = i ^ (i >> 1);
        cout << gray << " ";
    }
    cout << endl;
    cout << "二进制" << endl;
    for (int i = 0; i < tol; i++) {
        int gray = i ^ (i >> 1);
        cout << bitset<16>(gray).to_string().substr(16-n) << " ";
    }
    cout << endl;
    cout << "递归：" << endl;
    vector<string> res = gray(n);
    for (auto s : res) {
        cout << s << " ";
    }
    return 0;
}