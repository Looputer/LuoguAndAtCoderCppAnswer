//
// Created by 陆熠辰 on 26-3-6.
//
#include <iostream>
using namespace std;

const int INF = 1e9;
struct Node {
    int value;
    Node *left, *right;
    Node(int val) {
        value = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->value) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

bool find(Node* root, int val) {
    if (root == NULL) return false;
    if (root->value == val) return true;
    if (val < root->value) return find(root->left, val);
    return find(root->right, val);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

Node* findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

Node* remove(Node* root, int val) {
    if (root == NULL) return NULL;
    if (val < root->value) root->left = remove(root->left, val);
    else if (val > root->value) root->right = remove(root->right, val);
    else {
        if (root->left == NULL) return root->right;
        if (root->right == NULL) return root->left;
        Node* temp = findMin(root->right);
        root->value = temp->value;
        root->right = remove(root->right, temp->value);
    }
    return root;
}

void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->value << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->value << " ";
}

bool check(Node* root, int minVal = INF, int maxVal = INF) {
    if (root == NULL) return false;
    if (root->value < minVal || root->value > maxVal) return false;
    return check(root->left, minVal, root->value) && check(root->right, root->value, maxVal);
}