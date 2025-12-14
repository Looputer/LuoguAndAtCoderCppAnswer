//
// Created by 陆熠辰 on 25-11-23.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int mp[1005][1005];
vector<int> v[1005];
int main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = mp[y][x] = 1;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1;i <= n;i++) {
        cout << v[i].size() << " ";
        sort(v[i].begin(), v[i].end());
        for (auto u : v[i]) {
            cout << u << " ";
        }
        cout << endl;
    }
    return 0;
}