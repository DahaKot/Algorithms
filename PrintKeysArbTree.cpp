#include <iostream>

#include <iostream>

class Node {
public:
    int key;
    Node* left_child;
    Node* right_sibling;
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
    void printKeys() {
        Stack nodes;
        nodes.n = 0;

        nodes.push(root);

        while(!nodes.isEmpty()) {
            Node* elem = nodes.pop();

            if (elem != nullptr) {
                std::cout << elem->key << std::endl;
                nodes.push(elem->right_sibling);
                nodes.push(elem->left_child);
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
    tree.root->left_child = &a;
    Node b = {3, nullptr, nullptr};
    tree.root->left_child->right_sibling = &b;
    Node c = {4, nullptr, nullptr};
    tree.root->left_child->left_child = &c;
    Node d = {5, nullptr, nullptr};
    tree.root->left_child->right_sibling->left_child = &d;
    Node e = {6, nullptr, nullptr};
    tree.root->left_child->right_sibling->left_child->right_sibling = &e;

    tree.printKeys();

    return 0;
}
