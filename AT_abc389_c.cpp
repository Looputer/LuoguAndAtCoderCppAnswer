#include <iostream>
#include <deque>
#define int long long
using namespace std;

const int MaxN = 3 * 1e5 + 5;
int q, head, s[MaxN], idx = 1, h;
deque<int> d;
void operate1(int l) {
    d.push_back(l);
    idx++;
    s[idx] = s[idx - 1] + l;
}

void operate2() {
    h += d.front();
    d.pop_front();
    head++;
}

void operate3(int k) {
    cout << s[head + k] - h<< endl;
}

signed main() {
    cin >> q;
    d.push_front(0);
    while (q--) {
        int o;
        cin >> o;
        switch (o) {
            case 1: {
                int l;
                cin >> l;
                operate1(l);
                break;
            }
            case 2: {
                operate2();
                break;
            }
            case 3: {
                int k;
                cin >> k;
                operate3(k);
                break;
            }
        }
    }
    return 0;
}