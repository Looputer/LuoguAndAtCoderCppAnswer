#include <iostream>
#include <string>
#define int long long
using namespace std;

const int MaxN = 1e6+5;
int n, m;
int d[MaxN];
string s;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    while (m--) {
        char op;
        int l, r;
        cin >> op >> l >> r;
        if (op == '+') {
            d[l]++;
            d[r+1]--;
        } else {
            d[l]--;
            d[r+1]++;
        }
    }
    for (int i = 1; i <= n; i++) d[i] += d[i - 1];
    for (int i = 1; i <= n; i++) {
        int x;
        if (s[i] == 'R') x = 0;
        else if (s[i] == 'S') x = 1;
        else x = 2;
        int k = ((d[i] % 3) + 3) % 3;
        x = (x + k) % 3;
        if (x == 0) cout << 'R';
        else if (x == 1) cout << 'S';
        else cout << 'P';
    }
}