#include <iostream>
#include <map>
#define int long long
using namespace std;

int n, q;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<int, int> mp;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x] = i;
    }
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << mp[x] << endl;
    }
    return 0;
}