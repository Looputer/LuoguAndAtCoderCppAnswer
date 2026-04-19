#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MOD = 1e9+7;
int k;

struct Matrix {
    int a[10][10];
    Matrix() {
        memset(a, 0, sizeof(a));
    }
};
Matrix M, init;

Matrix operator * (const Matrix &A, const Matrix &B) {
    Matrix C;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (!A.a[i][j]) continue;
            for (int k = 0; k < 10; k++) {
                C.a[i][k] = (C.a[i][k] + A.a[i][j] * B.a[j][k]) % MOD;
            }
        }
    }
    return C;
}

Matrix qpow(Matrix A, int b) {
    Matrix res;
    for (int i = 0; i < 10; i++) res.a[i][i] = 1;
    while (b) {
        if (b & 1) res = res * A;
        A = A * A;
        b >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (abs(i-j) <= 2) M.a[i][j] = 1;
        }
    }
    for (int i = 1; i < 10; i++) init.a[i][0] = 1;
    if (k == 1) {
        cout << 9 << endl;
        return 0;
    }
    Matrix MK = qpow(M, k - 1);
    Matrix res = MK * init;
    int ans = 0;
    for (int i = 0; i < 10; i++) ans = (ans + res.a[i][0]) % MOD;
    cout << ans << endl;
    return 0;
}