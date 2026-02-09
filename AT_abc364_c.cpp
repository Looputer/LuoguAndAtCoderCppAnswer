//
// Created by 陆熠辰 on 26-2-27.
//
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int MaxN = 2e5+5;
struct Meal {
    int a, b;
};

bool cmpA(const Meal &m1, const Meal &m2) {
    return m1.a > m2.a;
}
bool cmpB(const Meal &m1, const Meal &m2) {
    return m1.b > m2.b;
}
int n, x, y;
Meal meals[MaxN];

signed main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> meals[i].a;
    }
    for (int i = 1; i <= n; i++) {
        cin >> meals[i].b;
    }
    sort(meals + 1, meals + n + 1, cmpA);
    int i, j, sum_a = 0, sum_b = 0;
    for (i = 1; i <= n; i++) {
        sum_a += meals[i].a;
        if (sum_a > x) break;
    }
    sort(meals + 1, meals + n + 1, cmpB);
    for (j = 1; j <= n; j++) {
        sum_b += meals[i].b;
        if (sum_b > y) break;
    }
    cout << min(i, j) << endl;
}