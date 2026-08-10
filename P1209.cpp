#include<algorithm>
#include<iostream> 
#define int long long
using namespace std;

const int MaxN = 205;
int m,s,c,ans;
int a[MaxN],C[MaxN];

bool cmp(int x,int y)
{
    return x>y;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> s >> c;
    for(int i = 1;i <= c;i++)
        cin >> a[i];
    if(m > c) {
        cout << c;
        return 0;
    }
    sort(a+1,a+c+1);
    ans = a[c] - a[1] +1;
    for(int i = 2; i <= c; i++)
        C[i-1] = a[i] - a[i-1];
    sort(C+1,C+c,cmp);
    for(int i = 1; i <= m - 1; i++)
        ans = ans- C[i] + 1;
    cout << ans << endl;
} 

