#include <iostream>
#include <queue>

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

    int dfs(Node* node) {
        if (root == nullptr) {
            return 0;
        }

        queue<Node*> q;
        Node* current = node;
        q.push(current);
        int count = 1;

        while (!q.empty()) {
            current = q.front();
            q.pop();
            if (current->left != nullptr) {
                q.push(current->left);
                count += 1;
            }
            if (current->right != nullptr) {
                q.push(current->right);
                count += 1;
            }
        }
        return count;
    }

    // void print() {
    //     inorder_walk(root);
    // }

    int get_subtree_size(int key) {
        Node* current = root;
        while (current->key != key) {
            if (current->key > key) {
                current = current->left;
            } else if (current->key < key) {
                current = current->right;
            }
        }
        return dfs(current);
        
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
    int n; cin >> n;
    int val;

    BST b;

    for (int i = 0; i < n; i++) {
        cin >> val;
        b.insert(val);
    }

    int k; cin >> k;
    cout << b.get_subtree_size(k);
}