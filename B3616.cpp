#include <iostream>
#include <queue>
#define int long long
using namespace std;

int n;
queue<int> q;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (x == 1) {
            int y;
            cin >> y;
            q.push(y);
        }
        else if (x == 2) {
            try {
                q.pop();
            }
            
            }
        }
    }
}