#include <iostream>
#include <set>
#define int long long
using namespace std;

int q, L;
set<int> st;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> L >> q;
    st.insert(1);
    st.insert(L+1);
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) st.insert(x+1);
        else {
            auto it = st.upper_bound(x);
            auto r = it; 
            it--;
            auto l = it;
            cout << *r - *l << endl;
        }
    }
}