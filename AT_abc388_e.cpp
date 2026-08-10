//
// Created by 陆熠辰 on 2026/7/26.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 5e5+5;
int n, a[MaxN];

int check(int mid) {
   for (int i = 1; i <= mid; i++) {
      if (a[i] * 2 > a[i + mid]) return 0;
   }
   return 1;
}

signed main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin >> n;
   for (int i = 1; i <= n; i++) cin >> a[i];
   int ans = 0;
   int l = 0, r = n / 2;
   while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid)) {
         ans = mid;
         l = mid + 1;
      } else {
         r = mid;
      }
   }
   cout << ans << endl;
}