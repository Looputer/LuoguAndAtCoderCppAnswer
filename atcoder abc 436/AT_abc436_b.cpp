//
// Created by 陆熠辰 on 25-12-15.
//
#include <iostream>
using namespace std;

const int MaxN = 105;
int a[MaxN][MaxN];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int r = 0, c = n / 2;
    a[r][c] = 1;
    for (int i = 2; i <= n * n; i++) {
        int r1 = (r - 1 + n) % n;
        int c1 = (c + 1) % n;
        if (a[r1][c1] == 0) {
            r = r1;
            c = c1;
        }
        else {
            r = (r + 1) % n;
        }
        a[r][c] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}