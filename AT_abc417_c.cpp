#include <iostream>
#include <map>
#define int long long
using namespace std;

int n;
map<int, int> cnt;
int ans = 0;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ans += cnt[i - x];
        cnt[i + x]++;
    }
    cout << ans;
    return 0;
}