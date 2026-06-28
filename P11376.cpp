#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

const int MaxN = 1e5+5;
int m, n, x;
int p[MaxN], c[MaxN], id[MaxN];
int ans;

struct node {
    int a, b, minus;
};

vector<node> pos, neg;

bool cmp1(node a, node b) {
    return a.minus > b.minus;
}

bool cmp2(node a, node b) {
    return a.minus < b.minus;
}

bool cmp_station(int i, int j) {
    return p[i] < p[j];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> c[i];
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp_station);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (a - b > 0) {
            pos.push_back({a, b, a-b});
        } else {
            neg.push_back({a, b, a-b});
        }
    }
    sort(pos.begin(), pos.end(), cmp1);
    sort(neg.begin(), neg.end(), cmp2);
    int idx = 1;
    for (auto [a, b, minus] : pos) {
        while (idx <= n && c[id[idx]] == 0) idx++;
        if (idx > n) break;
        ans += 2 * x * b + 2 * p[id[idx]] * minus;
        c[id[idx]]--;
    }
    idx = n;
    for (auto [a, b, minus] : neg) {
        while (idx >= 1 && c[id[idx]] == 0) idx--;
        if (idx < 1) break;
        ans += 2 * x * b + 2 * p[id[idx]] * minus;
        c[id[idx]]--;
    }
    cout << ans << endl;
}