//
// Created by 陆熠辰 on 25-11-16.
//
#include <iostream>
using namespace std;
const int MaxN = 1e5+5;
int a[MaxN], s[MaxN];
int main() {
    int n;
    cin>>n;
    for (int i = 1;i <= n;i++) {
        cin>>a[i];
        s[i] = s[i - 1] + a[i];
    }
    int x, y;
    cin>>x>>y;
    for (int i = 1;i <= n;i++) {
        int a = s[i-1];
        int b = s[n] - s[i-1];
        if (a >= x && a <= y && b >= x && b <= y) {
            cout << i << endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}