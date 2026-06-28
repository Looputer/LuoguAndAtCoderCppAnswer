#include <iostream>
#define int long long
using namespace std;

const int MaxN = 1e6+5;
int l[MaxN], r[MaxN], n;

void preOrder(int u) {
    if (u == 0) return;
    cout << u << " ";
    preOrder(l[u]);
    preOrder(r[u]);
}

void midOrder(int u) {
    if (u == 0) return;
    midOrder(l[u]);
    cout << u << " ";
    midOrder(r[u]);
}

void postOrder(int u) {
    if (u == 0) return;
    postOrder(l[u]);
    postOrder(r[u]);
    cout << u << " ";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    preOrder(1);
    cout << endl;
    midOrder(1);
    cout << endl;
    postOrder(1);
    cout << endl;
}