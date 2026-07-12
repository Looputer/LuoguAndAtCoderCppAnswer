#include <iostream>
#include <set>
#include <vector>
#define int long long
using namespace std;

int n;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<vector<int>> st;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int len;
        cin >> len;
        vector<int> tmp;
        for (int i = 1; i <= len; i++) {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        st.insert(tmp);
    }
    cout << st.size() << endl;
}