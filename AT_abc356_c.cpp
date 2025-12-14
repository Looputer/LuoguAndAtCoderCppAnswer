//
// Created by 陆熠辰 on 25-11-16.
//
#include <iostream>
using namespace std;

int n, m, k, ans;
bool flag[20];
int cnt[20], key[105][20];
char res[20];
void dfs(int u) {
    if (u == n + 1) {
        for (int i = 1;i <= m;i++) {
            int sum = 0;
            for (int j = 1;j <= cnt[i];j++) {
                int k = key[i][j];
                sum += flag[k];
            }
            if (sum >= k && res[i] == 'x') return;
            if (sum < k && res[i] == 'o') return;
        }
        ans++;
        return;
    }
    flag[u] = true; dfs(u+1);
    flag[u] = false; dfs(u+1);
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> cnt[i];
        for (int j = 1; j <= cnt[i]; j++) {
            cin >> key[i][j];
        }
        cin >> res[i];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}