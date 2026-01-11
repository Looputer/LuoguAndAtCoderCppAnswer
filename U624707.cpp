//
// Created by 陆熠辰 on 25-12-23.
//
#include <iostream>
using namespace std;

int t, n, op, k;
int othercard[15];
int owncard[20];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> op >> k;
        for (int i = 1; i <= k; i++) {
            cin >> othercard[i];
            if (othercard[i] >= 3 && othercard[i] <= 13) {
                othercard[i] -= 3;
            }
            else if (othercard[i] >= 1 && othercard[i] <= 2) {

            }
        }
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> owncard[i];
    }

}