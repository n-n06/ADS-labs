#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    Node* parent;
    Node* left;
    Node* right;
    int key;

    Node(int key) {
        this->key = key;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
private:
    Node* root;
    
    void inorder_traversal(Node* node) {
        if (node != nullptr) {
            inorder_traversal(node->right);
            cout << node->key << " ";
            inorder_traversal(node->left);
        }
    }


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

    void swap_with_sum() {
        stack <Node*> st;

        Node* current = root;
        int sum = 0;

        while (!st.empty() || current != nullptr) {
            while (current != nullptr) {
                st.push(current);
                current = current->right;
            }

            current = st.top();
            st.pop();
            sum += current->key;
            current->key = sum;

            current = current->left;
        }
    }    

    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }


    void print() {
        inorder_traversal(root);
    }

    ~BST() {
        clear(root);
    };
};

int main() {
    int n; cin >> n;
    int a;

    BST b;

    for (int i = 0; i < n; i++) {
        cin >> a;
        b.insert(a);
    }

    b.swap_with_sum();
    b.print();

}