//
// Created by 陆熠辰 on 26-1-1.
//
#include <iostream>
using namespace std;

int main() {
    int d, f;
    cin >> d >> f;
    cout << (f + (d - f) * 7) % d;
}