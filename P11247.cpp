#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int m, n, k;
int cnt[MaxN];

struct Problem {
    int id, score;
}p[MaxN];

bool cmp(Problem x, Problem y) {
    if (x.id != y.id) return x.id < y.id;
    return x.score > y.score;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].id;
        cnt[p[i].id]++;
    }
    for (int i = 1; i <= n; i++) cin >> p[i].score;
    sort(p+1, p+n+1, cmp);
    int tol = 0;
    int idx = 1;
    for (int i = 1;i <= m; i++) {
        int ap = cnt[i];
        if (k == 0) {
            idx += ap;
            continue;
        }
        int sum = 0, cnt = 0, satisfied = 0;
        for (int j = 0; j < ap; j++) {
            if (sum >= k) {
                satisfied = 1;
                break;
            }
            sum += p[idx].score;
            cnt++;
            idx++;
            if (sum >= k) {
                satisfied = 1;
                break;
            }
        }
        if (!satisfied) {
            cout << -1 << endl;
            return 0;
        }
        int remaining = ap - cnt;
        idx += remaining;
        tol += cnt;
    }
    if (m == 1 && tol > 1) cout << -1 << endl;
    else cout << tol << endl;
}