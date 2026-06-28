#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> pos, neg;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        if (x > 0)
            pos.push_back(x);
        else
            neg.push_back(x);
    }

    if (pos.empty()) {
        cout << 0;
        return 0;
    }

    int ans = 0;
    int mx = 0;

    for (int x : pos) {
        ans += x;
        mx = max(mx, x);
    }

    if (!neg.empty()) {
        int mn = 0;
        for (int x : neg)
            mn = min(mn, x);

        ans += mx - mn;
    } else {
        int mn = pos[0];
        for (int x : pos)
            mn = min(mn, x);

        ans += mx - mn;
    }

    cout << ans;
    return 0;
}