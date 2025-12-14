//
// Created by 陆熠辰 on 25-12-9.
//
#include <iostream>
using namespace std;

int a[55], s[55];
int n;
int cnt;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int flag = 0;
            int sum = s[j] - s[i - 1];
            for (int k = i;k <= j;k++) {
                if (sum % a[k] == 0) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) cnt++;
        }
    }
    cout << cnt << endl;
}