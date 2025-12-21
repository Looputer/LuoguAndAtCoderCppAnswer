#include <iostream>
#define int long long
using namespace std;

const int MaxN = 3e5 + 5;
struct Reindeer {
    int p, w, sum;
}reindeer[MaxN];
int t, n, s;

bool cmp(Reindeer a, Reindeer b) {
    return a.sum < b.sum;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        s = 0;
        for (int i = 1;i <= n;i++) {
            cin >> reindeer[i].w >> reindeer[i].p;
            reindeer[i].sum = reindeer[i].p + reindeer[i].w;
            s += reindeer[i].p;
        }
        sort(reindeer + 1, reindeer + n + 1, cmp);
        int ans = 0;
        int right = 0;
        for (int i = 1;i <= n;i++) {
            right = reindeer[i].sum;
            if (s >= right) {
                s -= right;
                ans++;
            } else {
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
