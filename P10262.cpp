#include <iostream>
#include <string>
#define int long long
using namespace std;
int p, ans, cnt[130], tmp[130];
string s;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> p >> s;

    for (auto ch : s) {
        int d = ch - '0';
        for (int v = 0; v < p ; v++) tmp[v] = 0;
        for (int v = 0; v < p ; v++) 
            if (cnt[v] > 0) tmp[(v * 10 + d) % p] += cnt[v];
        tmp[d % p]++;
        ans += tmp[0];
        for (int v = 0; v < p ; v++) cnt[v] = tmp[v];
    }
    cout << ans << endl;
}