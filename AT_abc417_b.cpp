#include <iostream>
#include <set>
#define int long long
using namespace std;

multiset<int> s;
int n, m;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }
    while (m--) {
        int b;
        cin >> b;
        auto it = s.find(b);
        if (it != s.end()) s.erase(it);
    }
    for (auto x : s) cout << x << " ";
}