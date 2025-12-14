//
// Created by 陆熠辰 on 25-11-22.
//
#include <iostream>
using namespace std;

int a[15];
int c[15];
int n;
int minn = 1e9;
void dfs(int u, int s, int b) {
    if (u == n + 1) {
        if (s == 1 && b == 0) return;
        minn = min(abs(s-b), minn);
        return;
    }
    dfs(u + 1, s * a[u], b + c[u]);
    dfs(u + 1, s, b);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }
    dfs(1, 1, 0);
    cout << minn << endl;
    return 0;
}