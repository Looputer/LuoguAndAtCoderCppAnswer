#include <iostream>
#include <set>
#define int long long
using namespace std;

int m;
set<int> st;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m;
    st.insert(-1e18);
    st.insert(1e18);
    while (m--) {
        int op, length;
        cin >> op >> length;
        if (op == 1) {
            if (st.count(length)) cout << "Already Exist" << endl;
            else st.insert(length);
        } else {
            if (st.size() == 2) {
                cout << "Empty" << endl;
                continue;
            }
            if (st.count(length)) {
                st.erase(length);
                cout << length << endl;
                continue;
            }
            auto it = st.lower_bound(length);
            auto before = it;
            auto after = it;
            before--;
            if ((length - *before) <= (*after - length)) {
                cout << *before << endl;
                st.erase(*before);
            } else {
                cout << *after << endl;
                st.erase(*after);
            }
        }
    }
}