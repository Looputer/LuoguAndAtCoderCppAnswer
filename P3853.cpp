#include <iostream>
#define int long long
using namespace std;

const int MaxN = 100005;

int L, N, K;
int a[MaxN];


int check(int x) {
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        int dis = a[i] - a[i-1];
        cnt += (dis + x - 1) / x - 1;
        if (cnt > K)
            return 0;
    }
    return 1;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> L >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int l = 1;
    int r = L;
    int ans = L;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}