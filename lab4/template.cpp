#include <iostream>

using namespace std;


class Node 
{
public:
    int key;
    Node* parent;
    Node* left;
    Node* right;

    Node(int key) {
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        this->key = key;
    }
};

class BST
{
private:
    Node* root;
public:
    BST() {
        root = nullptr;
    };

    void insert(int new_key) {
        Node* new_node = new Node(new_key);
        Node* x = root;
        Node* y = nullptr;

        while (x != nullptr) {
            y = x;
            if (x->key > new_key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        if (y == nullptr) {
            root = new_node;
        } else if (new_key < y->key) {
            y->left = new_node;
            new_node->parent = y;
        } else {
            y->right = new_node;
            new_node->parent = y;
        }
    }

    void inorder_walk(Node* node) {
        if (node != nullptr) {
            inorder_walk(node->left);
            cout << node->key << " "; 
            inorder_walk(node->right);
        }
    }

    void print() {
        inorder_walk(root);
    }

    ~BST() {
        clear(root);
    }

    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
};

int main() {
    
}