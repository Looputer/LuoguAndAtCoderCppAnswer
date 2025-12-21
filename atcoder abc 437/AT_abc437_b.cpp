//
// Created by 陆熠辰 on 25-12-20.
//
#include <iostream>
#include <algorithm>
using namespace std;

int a[10][10], b[95], cnt[105];
int h, w, n;

bool cmp(int a, int b) {
    return a > b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w >> n;
    for (int i = 1;i <= h; i++) {
        for (int j = 1;j <= w;j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1;i <= n;i++) {
        cin >> b[i];
    }
    for (int i = 1;i <= h;i++) {
        int c = 0;
        for (int j = 1;j <= w;j++) {
            for (int k = 1;k <= n;k++) {
                if (a[i][j] == b[k]) c++;
            }
        }
        cnt[i] = c;
    }
    sort(cnt+1, cnt+n+1, cmp);
    cout << cnt[1] << endl;
    return 0;
}
