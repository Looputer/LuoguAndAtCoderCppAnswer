//
// Created by 陆熠辰 on 26-2-27.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int MaxN = 1e3+5;
int n, m, k;
string s;
vector<int> edge[MaxN];
int vis[MaxN];

vector<int> moveto(int to) {
    cout << to << endl;
    string s;
    cin >> s;
    if (s == "OK" || s == "-1") exit(0);
    int k = stoi(s);
    vector<int> move;
    for (int i = 0; i < k; i++) {
        int movepoint;
        cin >> movepoint;
        move.push_back(movepoint);
    }
    return move;
}

void dfs(int u, vector<int> move) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto v : move) {
        if (!vis[v]) {
            vector<int> next_move = moveto(v);
            dfs(v, next_move);
            moveto(u);
        }
    }
}

signed main() {
    cin >> n >> m;
    int k;
    cin >> k;
    vector<int> first_move;
    for (int i = 0; i < k; i++) {
        int v;
        cin >> v;
        first_move.push_back(v);
    }
    dfs(1, first_move);
    return 0;
}
