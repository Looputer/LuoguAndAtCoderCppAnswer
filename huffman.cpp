//
// Created by 陆熠辰 on 26-3-6.
//
#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    char str;
    int freq;
    Node *left, *right;
    Node(char ch, int fre) {
        str = ch;
        freq = fre;
        left = right = NULL;
    }
};

struct cmp {
    bool operator () (Node *a, Node *b) {
        return a->freq > b->freq;
    }
};

void getCode(Node *root, string code, map<char, string> &mp) {
    if (!root) return;
    if (!root->left && !root->right) {
        mp[root->str] = code;
    }
    getCode(root->left, code + "0", mp);
    getCode(root->right, code + "1", mp);
}


signed main() {
    string s;
    cin >> s;
    s = " " + s;
    priority_queue<int, vector<int>, greater<int> > weight;
    int wpl = 0;
    for (int i = 1; i <= s.length(); i++) {
        int x;
        cin >> x;
        weight.push(x);
    }
    while (weight.size() > 1) {
        int a = weight.top();
        weight.pop();
        int b = weight.top();
        weight.pop();
        wpl += a + b;
        weight.push(a + b);
    }
    map<char, int> freq;
    for (char c : s) {
        if (c == ' ') continue;
        freq[c]++;
    }
    priority_queue<Node*, vector<Node*>, cmp> pq;
    for (auto p : freq) {
        pq.push(new Node(p.first, p.second));
    }
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    Node* root = pq.top();
    map<char, string> code;
    getCode(root, "", code);
    for (auto p : code) {
        cout << p.first << " : " << p.second << endl;
    }
    cout << "WPL : " << wpl << endl;
    return 0;
}