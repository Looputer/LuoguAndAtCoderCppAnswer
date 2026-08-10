//
// Created by 陆熠辰 on 2026/8/9.
//
#include <iostream>
#include <queue>
#include <vector>
#define int long long
using namespace std;

priority_queue<int> q1;  //大根堆
priority_queue<int, vector<int>, greater<int> > q2;   //小根堆

int n, mid;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int first;
    cin >> first;
    q1.push(first);
    cout << q1.top() << endl;
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        if (i % 2 == 0) {
            if (a > q1.top()) {
                q2.push(a);
            } else {
                q2.push(q1.top());
                q1.pop();
                q1.push(a);
            }
        } else {
            if (a > q2.top()) {
                q2.push(a);
                q1.push(q2.top());
                q2.pop();
            } else {
                q1.push(a);
            }
            cout << q1.top() << endl;
        }

    }
}