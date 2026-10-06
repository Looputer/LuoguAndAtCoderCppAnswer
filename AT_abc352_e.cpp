//
// Created by 陆熠辰 on 2026/9/12.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
struct Node {
    int c;
    vector<int> a;
};

int n, m;
int p[MaxN];

int pfind(int x) {
    if (p[x] == x) return x;
    return p[x] = pfind(p[x]);
}

bool cmp(Node a, Node b) {
    return a.c < b.c;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
}