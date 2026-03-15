#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int p;
    string s;
    cin >> p >> s;

    int n = s.size();
    long long ans = 0;

    if (p == 2 || p == 5) {
        for (int i = 0; i < n; i++) {
            if ((s[i] - '0') % p == 0)
                ans += i + 1;
        }
    }
    else {
        vector<long long> cnt(p, 0);

        long long cur = 0, pow10 = 1;
        cnt[0] = 1;

        for (int i = n - 1; i >= 0; i--) {
            cur = (cur + (s[i] - '0') * pow10) % p;

            ans += cnt[cur];
            cnt[cur]++;

            pow10 = pow10 * 10 % p;
        }
    }

    cout << ans;
    return 0;
}