#include <iostream>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
int n, u[MaxN], d[MaxN], l[MaxN], r[MaxN];
int a[2005][2005], cnt[2005][2005], sum[2005][2005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> u[i] >> d[i] >> l[i] >> r[i];
        a[u[i]][l[i]]++;
        a[d[i] + 1][l[i]]--;
        a[u[i]][r[i] + 1]--;
        a[d[i] + 1][r[i] + 1]++;
    }
    int z = 0;
    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= 2000; j++) {
            cnt[i][j] = a[i][j] + cnt[i - 1][j] + cnt[i][j-1] - cnt[i-1][j-1];
            if (cnt[i][j] == 0) z++;
            sum[i][j] = (cnt[i][j] == 1);
        }
    }
    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= 2000; j++) {
            sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    int cntt = 0;
    for (int i = 1; i <= n; i++) {
        cntt = sum[d[i]][r[i]] - sum[u[i] - 1][r[i]] - sum[d[i]][l[i] - 1] + sum[u[i] - 1][l[i] - 1];
        cout << z + cntt << endl;
    }
}