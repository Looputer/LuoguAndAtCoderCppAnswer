//
// Created by 陆熠辰 on 25-11-9.
//
#include <iostream>
using namespace std;

int n;
int cnt;
vector<int> v;
int a[25];

void dfs(int u) {
    if (u == n + 1) {
        int sum = 0;
        int maxn = -1e9;
        for (auto c : v) {
            sum += a[c];
            if (a[c] > maxn) {
                maxn = a[c];
            }
        }
        if (v.size() >= 3 && sum > 2 * maxn) {
            cnt++;
        }
        return;
    }
    v.push_back(u);
    dfs(u+1);
    v.pop_back();
    dfs(u+1);
}

int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    dfs(1);
    cout << cnt << endl;
}