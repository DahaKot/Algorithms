#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;
};

class Stack {
public:
    void push(Node* x) {
        data[n++] = x;
    }
    Node* pop() {
        return data[--n];
    }
    bool isEmpty() {
        return n == 0;
    }

    Node* data[30];
    int n;
};


class BinaryTree {
public:
    void insert(Node* x, bool left) {
        if (left) {
            x->left = root;
        }
        else {
            x->right = root;
        }

        root = x;
    }
    void printKeys() {
        Stack nodes;
        nodes.n = 0;

        nodes.push(root);

        while(!nodes.isEmpty()) {
            Node* elem = nodes.pop();

            if (elem != nullptr) {
                std::cout << elem->key << std::endl;
                nodes.push(elem->right);
                nodes.push(elem->left);
            }
        }
    }
    Node* root;
};

int main() {
    Node root = {1, nullptr, nullptr};
    BinaryTree tree;
    tree.root = &root;

    Node a = {2, nullptr, nullptr};
    tree.root->left = &a;
    Node b = {3, nullptr, nullptr};
    tree.root->right = &b;
    Node c = {4, nullptr, nullptr};
    tree.root->left->right = &c;
    Node d = {5, nullptr, nullptr};
    tree.root->right->left = &d;
    Node e = {6, nullptr, nullptr};
    tree.root->right->right = &e;

    tree.printKeys();

    return 0;
}
