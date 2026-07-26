#include <iostream>
#include <set>
using namespace std;

const int MAXK = 200005;

int A[MAXK], B[MAXK];
multiset<int> kg[MAXK];
multiset<int> best;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        kg[B[i]].insert(A[i]);
    }

    for (int i = 1; i <= 200000; i++) {
        if (!kg[i].empty()) {
            best.insert(*kg[i].rbegin());
        }
    }

    while (Q--) {
        int c, d;
        cin >> c >> d;

        int old = B[c];

        // 删除原来的最高评分
        int x = *kg[old].rbegin();
        best.erase(best.find(x));

        if (!kg[d].empty()) {
            int y = *kg[d].rbegin();
            best.erase(best.find(y));
        }

        // 转园
        kg[old].erase(kg[old].find(A[c]));
        kg[d].insert(A[c]);
        B[c] = d;

        // 放入新的最高评分
        if (!kg[old].empty()) {
            best.insert(*kg[old].rbegin());
        }

        if (!kg[d].empty()) {
            best.insert(*kg[d].rbegin());
        }

        cout << *best.begin() << '\n';
    }

    return 0;
}