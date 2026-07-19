#include <iostream>
#include <set>
#define int long long
using namespace std;

multiset<int> st;
int q, del;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while (q--) {
        int op, x;
        cin >> op;
        if (op == 1) {
            cin >> x;
            st.insert(x - del);
        } else if (op == 2) {
            cin >> x;
            del += x;
        } else {
            cout << *st.begin() + del << endl;
            auto it = st.begin();
            st.erase(it);
        }
    }
}