//
// Created by 陆熠辰 on 25-12-22.
//
#include <iostream>
#include <deque>
#define int long long
using namespace std;

const int MaxN = 1e5+5;

struct Pokemon {
    int hp, mp, atk, sd, sc, ar, mr, spd;
    int time = 3;
};
deque<Pokemon> karl;
deque<Pokemon> mubao;

int n, m;
int atk_karl, atk_mubao;

void attack(Pokemon &a, Pokemon &b, bool isKarl) {
    int normal = a.atk - b.ar;
    int skill = a.sd - b.mr;
    if (a.sc > a.mp) skill = 0;
    if (normal > skill) {
        b.hp -= normal;
        if (isKarl) atk_karl += normal;
        else atk_mubao += normal;
    }
    else {
        a.mp -= a.sc;
        b.hp -= skill;
        if (isKarl) atk_karl += skill;
        else atk_mubao += skill;
    }
}

int is_dead(Pokemon &p) {
    if (p.hp <= 0) return 1;
    return 0;
}

bool cmp(Pokemon p1, Pokemon p2) {
    return p1.spd > p2.spd;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        Pokemon p;
        cin >> p.hp >> p.mp >> p.atk >> p.sd >> p.sc >> p.ar >> p.mr >> p.spd;
        karl.push_back(p);
    }
    for (int i = 0;i < m;i++) {
        Pokemon p;
        cin >> p.hp >> p.mp >> p.atk >> p.sd >> p.sc >> p.ar >> p.mr >> p.spd;
        mubao.push_back(p);
    }
    while (karl.size() && mubao.size()) {
        Pokemon a = karl.front();
        Pokemon b = mubao.front();
        karl.pop_front();
        mubao.pop_front();
        a.time--;
        b.time--;
        if (a.spd >= b.spd) {
            attack(a, b, true);
            if (!is_dead(b)) attack(b, a, false);
        }
        else {
            attack(b, a, false);
            if (!is_dead(a)) attack(a, b, true);
        }
        if (!is_dead(a) && a.time > 0) karl.push_front(a);
        if (!is_dead(b) && b.time > 0) mubao.push_front(b);
    }
    cout << atk_karl << " " << atk_mubao << endl;
    return 0;
}