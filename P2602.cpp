#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define int long long

vector<int> digit;

struct Node {
    int cnt;
    int num[10];

    Node() {
        cnt = 0;
        memset(num, 0, sizeof(num));
    }
};

Node dp[20][2];
bool vis[20][2];

Node dfs(int pos, bool lead, bool limit) {
    if (pos == -1) {
        Node res;
        res.cnt = 1;
        return res;
    }

    if (!limit && vis[pos][lead]) return dp[pos][lead];

    int up = limit ? digit[pos] : 9;

    Node res;

    for (int d = 0; d <= up; d++) {
        bool nlead = lead && (d == 0);
        bool nlimit = limit && (d == up);

        Node tmp = dfs(pos - 1, nlead, nlimit);

        // 累加子树信息
        res.cnt += tmp.cnt;

        for (int i = 0; i < 10; i++) {
            res.num[i] += tmp.num[i];
        }

        // ⭐ 当前位贡献
        if (!nlead) {
            res.num[d] += tmp.cnt;
        }
    }

    if (!limit) {
        vis[pos][lead] = true;
        dp[pos][lead] = res;
    }

    return res;
}

void solve(int n, int res[]) {
    if (n <= 0) {
        for (int i = 0; i < 10; i++) res[i] = 0;
        return;
    }

    digit.clear();
    memset(vis, 0, sizeof(vis));

    while (n) {
        digit.push_back(n % 10);
        n /= 10;
    }

    Node ans = dfs(digit.size() - 1, true, true);

    for (int i = 0; i < 10; i++) {
        res[i] = ans.num[i];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int A[10], B[10];

    solve(b, B);
    solve(a - 1, A);

    for (int i = 0; i < 10; i++) {
        cout << B[i] - A[i] << " ";
    }

    return 0;
}