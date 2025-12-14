//
// Created by 陆熠辰 on 25-12-11.
//
#include <iostream>
using namespace std;

int q, x, y;

int father(int u) {
    for (int i = 2; i * i <= u; i++) {
        if (u % i == 0) {
            return u/i;
        }
    }
    return 1;
}

int dfs(int x, int y, int len) {
    if (x == y) {
        return len;
    }
    if (x % y == 0) {
        return dfs(father(x), y, len + 1);
    }
    if (y % x == 0) {
        return dfs(x, father(y), len + 1);
    }
    return dfs(father(x), father(y), len + 2);
}

int main() {
    cin >> q;
    while (q--) {
        cin >> x >> y;
        cout << dfs(x, y, 0) << endl;
    }
    return 0;
}