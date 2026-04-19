#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define int long long

vector<int> digit;

struct Node {
    long long cnt, sum;
    Node() { cnt = sum = 0; }
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

        res.cnt += tmp.cnt;
        res.sum += tmp.sum;

        // ⭐ 当前位贡献
        if (!nlead) {
            res.sum += d * tmp.cnt;
        }
    }

    if (!limit) {
        vis[pos][lead] = true;
        dp[pos][lead] = res;
    }

    return res;
}

long long solve(long long n) {
    if (n <= 0) return 0;

    digit.clear();
    memset(vis, 0, sizeof(vis));

    while (n) {
        digit.push_back(n % 10);
        n /= 10;
    }

    Node ans = dfs(digit.size() - 1, true, true);
    return ans.sum;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    cout << solve(n) << "\n";
    return 0;
}