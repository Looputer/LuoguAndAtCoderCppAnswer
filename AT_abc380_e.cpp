#include <iostream>
#include <set>
using namespace std;

const int N = 5e5+5;

int fa[N];
int L[N], R[N];
int col[N];

long long cnt[N];

set<int> S[N];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return x;

    if (R[x] - L[x] < R[y] - L[y])
        swap(x, y);

    fa[y] = x;

    L[x] = min(L[x], L[y]);
    R[x] = max(R[x], R[y]);

    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        L[i] = R[i] = i;
        col[i] = i;

        cnt[i] = 1;
        S[i].insert(i);
    }

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x, c;
            cin >> x >> c;

            int rt = find(x);
            int old = col[rt];

            if (old == c) continue;

            int len = R[rt] - L[rt] + 1;

            cnt[old] -= len;
            cnt[c] += len;

            S[old].erase(rt);

            if (S[old].size() > S[c].size()) {
                swap(S[old], S[c]);
            }

            for (int v : S[old]) {
                col[v] = c;
                S[c].insert(v);
            }
            S[old].clear();

            col[rt] = c;

            if (L[rt] > 1) {
                int left = find(L[rt] - 1);
                if (col[left] == c) {
                    rt = unite(left, rt);
                }
            }

            rt = find(rt);

        
            if (R[rt] < n) {
                int right = find(R[rt] + 1);
                if (col[right] == c) {
                    unite(rt, right);
                }
            }
        }
        else {
            int c;
            cin >> c;
            cout << cnt[c] << '\n';
        }
    }

    return 0;
}