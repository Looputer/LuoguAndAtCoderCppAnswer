//
// Created by 陆熠辰 on 25-12-10.
//
#include <iostream>
#include <set>
#define int long long
using namespace std;

int n, q;
set<pair<int,int>> st;

signed main() {
    cin >> n >> q;
    int black = 0;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = L, r = R;
        auto it = st.lower_bound({L, -1});
        if (it != st.begin()) {
            it--;
        }
        vector<decltype(st.begin())> erase_list;
        while (it != st.end()) {
            int left = it->first, right = it->second;
            if (right < l - 1 || left > r + 1) {
                if (left > r + 1) break;
                it++;
                continue;
            }
            l = min(l, left);
            r = max(r, right);
            black -= (right - left + 1);
            erase_list.push_back(it);
            it++;
        }
        for (auto e : erase_list) {
            st.erase(e);
        }
        st.insert({l, r});
        black += (r - l + 1);
        cout << (n - black) << endl;
    }
    return 0;
}