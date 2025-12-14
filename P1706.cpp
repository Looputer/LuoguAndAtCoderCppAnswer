//
// Created by 陆熠辰 on 25-11-22.
//
#include <iostream>
#include <vector>
using namespace std;
int vis[15];
vector<int> v;
int n;
void dfs(int u) {
    if (u == n + 1) {
        for (auto c : v) {
            cout << "    " << c;
        }
        cout << endl;
        return;
    }
    for (int i = 1;i <= n;i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        v.push_back(i);
        dfs(u + 1);
        vis[i] = 0;
        v.pop_back();
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}