//
// Created by 陆熠辰 on 25-11-16.
//
#include <iostream>
#include <vector>
using namespace std;

int n, k, r[10];
vector<int> v;
void dfs(int u) {
    if (u == n + 1) {
        int sum = 0;
        for (auto c : v) {
            sum += c;
        }
        if (sum % k == 0) {
            for (auto c : v) {
                cout << c << ' ';
            }
        }
        return;
    }
    for (int i = 1; i <= r[u]; i++) {
        v.push_back(i);
        dfs(u + 1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    dfs(1);
    return 0;
}