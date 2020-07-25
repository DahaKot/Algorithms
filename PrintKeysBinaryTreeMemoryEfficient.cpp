#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;
    Node* parent;
};

class BinaryTree {
public:
    void printKeys() {
        Node* cur = root->left;
        Node* prev = root;

        int i = 0;
        while(cur != prev) {
            if (cur == nullptr) {
                Node* tmp = cur;
                cur = prev;
                prev = tmp;
            }
            else if (prev == cur->right || cur->right == nullptr && cur->left == nullptr) {
                std::cout << cur->key << std::endl;
                prev = cur;
                cur = cur->parent;
                if (cur == nullptr) {
                    break;
                }
            }
            else if (prev == cur->left) {
                i++;
                prev = cur;
                cur = cur->right;
            }
            else if (prev == cur->parent) {
                prev = cur;
                cur = cur->left;
            }
            if (i == 10) {
                break;
            }
        }
        cur = root->right;
    }
    Node* root;
};

int main() {
    Node root = {1, nullptr, nullptr, nullptr};
    BinaryTree tree;
    tree.root = &root;

    Node a = {2, nullptr, nullptr, tree.root};
    tree.root->left = &a;
    Node b = {3, nullptr, nullptr, tree.root};
    tree.root->right = &b;
    Node c = {4, nullptr, nullptr, tree.root->left};
    tree.root->left->left = &c;
    Node z = {5, nullptr, nullptr, tree.root->left};
    tree.root->left->right = &z;
    Node d = {6, nullptr, nullptr, tree.root->right};
    tree.root->right->left = &d;
    Node e = {7, nullptr, nullptr, tree.root->right};
    tree.root->right->right = &e;
    Node f = {8, nullptr, nullptr, tree.root->left->left};
    tree.root->left->left->left = &f;
    Node g = {9, nullptr, nullptr, tree.root->left->left->left};
    tree.root->left->left->left->right = &g;
    Node h = {10, nullptr, nullptr, tree.root->left->right};
    tree.root->left->right->right = &h;
    Node i = {11, nullptr, nullptr, tree.root->left->right->right};
    tree.root->left->right->right->right = &i;
    Node j = {12, nullptr, nullptr, tree.root->left->right->right};
    tree.root->left->right->right->left = &j;
    Node k = {13, nullptr, nullptr, tree.root->right->right};
    tree.root->right->right->left = &k;

    tree.printKeys();

    return 0;
}
