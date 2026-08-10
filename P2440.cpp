//
// Created by 陆熠辰 on 2026/8/1.
//
#include <iostream>
#define int long long
using namespace std;

const int MaxN = 100005;
int n, k;
int a[MaxN];

bool check(int x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += a[i] / x;
        if (cnt >= k)
            return true;
    }
    return false;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        r = max(r, a[i]);
    }
    int l = 1;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}