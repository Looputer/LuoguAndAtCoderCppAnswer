//
// Created by 陆熠辰 on 25-10-12.
//
#include <iostream>
using namespace std;
const int MaxN = 1e9+5;
int k, cnt;
bool unique_number[MaxN];
bool is_unique_number(int n) {
    int vis[10] = {0};
    while (n) {
        int s = n % 10;
        if (vis[s] == 0) {
            vis[s] = 1;
            n /= 10;
            continue;
        }
        return false;
    }
    return true;
}

void dfs(int n) {
    if (n >= k) return;
    if (unique_number[n]) {
        cnt++;
    }
    dfs(n+1);
}

int main() {
    cin >> k;
    for (int i = 1; i <= k; i++) {
        unique_number[i] = is_unique_number(i);
    }
    dfs(1);
    cout << cnt << endl;
    return 0;
}

//Some TLE