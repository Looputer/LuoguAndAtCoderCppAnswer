#include <iostream>
#include <stack>
#define int long long 
using namespace std;

const int MaxN = 100005;
int q, n, a[MaxN], b[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while (q--) {
        stack<int> st;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        bool flag = false;
        int j = 1;
        for (int i = 1; i <= n; i++) {
            st.push(a[i]);
            while (st.top() == b[j] && j <= n) {
                st.pop();
                j++;
                if (st.size() == 0) break;
            }
        }
        if (st.size() == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}