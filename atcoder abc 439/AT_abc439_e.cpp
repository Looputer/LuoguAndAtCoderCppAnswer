//
// Created by 陆熠辰 on 26-1-3.
//
#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int> > seg(n);
    for(int i=0;i<n;i++) {
        cin>>seg[i].first>>seg[i].second;
    }
    sort(seg.begin(),seg.end(), [](const auto a, const auto b) {
        if (a.first==b.first) return a.second>b.second;
        else return a.first<b.first;
    });
    vector<int> lis;
    for(int i=0;i<n;i++) {
        int b = seg[i].second;
        auto it = upper_bound(lis.begin(),lis.end(),b);
        if (it == lis.end()) lis.push_back(b);
        else *it = b;
    }
    cout << lis.size() << endl;
}