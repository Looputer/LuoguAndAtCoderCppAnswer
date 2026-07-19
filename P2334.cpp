#include <iostream>
#include <set>
#define int long long
using namespace std;

int n;
set<int> st;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int sum = 0;
    st.insert(-1e18);
    st.insert(1e18);
    for (int i = 1; i <= n ;i++) {
        int x;
        cin >> x;
        if (i == 1) {
            sum += x;
            st.insert(x);
            continue;
        }
        if (st.count(x)) continue;
        
        auto it = st.lower_bound(x);
        auto before = it, after = it;
        before--;
        if ((x - *before) <= (*after - x)) {
            sum += abs(*before - x);
        } else {
            sum += abs(x - *after);
        }
        st.insert(x);
    }
    cout << sum;
}