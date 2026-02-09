//
// Created by 陆熠辰 on 26-2-27.
//
#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

struct Card {
    int a, c, id;
};

bool cmp(Card x, Card y) {
    return x.a > y.a;
}

vector<Card> cards;
vector<int> result;
int n;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, c;
        cin >> a >> c;
        cards.push_back({a, c, i});
    }
    sort(cards.begin(), cards.end(), cmp);
    int minn = 1e18;
    for (int i = 0; i < n; i++) {
        if (cards[i].c < minn) {
            minn = cards[i].c;
            result.push_back(cards[i].id);
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (auto i : result) {
        cout << i << ' ';
    }
    return 0;
}