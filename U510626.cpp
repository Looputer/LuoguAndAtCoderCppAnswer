#include <iostream>
#include <set>
#define int long long 
using namespace std;

int n, k, l, r;
set<int> st;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> l >> r;
    for (int i = 1; i <= k; i++) {
        int a;
        cin >> a;
        if (a < l || a > r) continue;
        st.insert(a);
    }
    cout << r - l + 1 - st.size();
}