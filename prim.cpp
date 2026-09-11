//
// Created by 陆熠辰 on 2026/9/6.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
int n, mp[MaxN][MaxN], st[MaxN], dist[MaxN];

int prim() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0, st[1] = 1;
    int sum = 0;
    for (int i = 1; i < n; i++) {
        int p = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (p == -1 || dist[p] > dist[j])) p = j;
        }
        st[p] = 1;
        sum += dist[p];
        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], mp[p][j]);
        }
    }
    return sum;
}