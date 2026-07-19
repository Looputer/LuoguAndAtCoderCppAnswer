#include <iostream>
#include <string>
#include <map>
#define int long long
using namespace std;

bool vis[4][13];
int n, cnt;
signed main() {
    cin >> n;
    map<string, bool> mp;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (!mp[s]) {
            mp[s] = true;
            cnt++;
        }
    }
    cout << 52 - cnt;
}