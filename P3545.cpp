#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 250005;

int n;
ll a[MAXN], b[MAXN];
bool selected[MAXN];

struct Item {
    ll val;
    int day;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    auto cmp = [](const Item& x, const Item& y) {
        return x.val < y.val;
    };
    priority_queue<Item, deque<Item>, decltype(cmp)> pq(cmp);

    ll stock = 0;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        stock += a[i];

        if (stock >= b[i]) {
            stock -= b[i];
            selected[i] = true;
            pq.push({b[i], i});
            cnt++;
        } else if (!pq.empty() && pq.top().val > b[i]) {
            Item top = pq.top();
            pq.pop();
            stock += top.val;     
            selected[top.day] = false;

            stock -= b[i];
            selected[i] = true;
            pq.push({b[i], i});
        }
    }

    cout << cnt << "\n";
    bool first = true;
    for (int i = 1; i <= n; i++) {
        if (selected[i]) {
            if (!first) cout << " ";
            cout << i;
            first = false;
        }
    }
    cout << "\n";

    return 0;
}