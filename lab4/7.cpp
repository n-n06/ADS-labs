#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

template <typename T>
class BST
{
private:
    int size;

    class Node {
    public:
        T key;
        Node* left;
        Node* right;
        Node* parent;

        Node(T key) {
            parent = nullptr;
            left = nullptr;
            right = nullptr;
            this->key = key;
        }
    };

    void inorder_walk(Node* node) {
        if (node != nullptr) {
            inorder_walk(node->left);
            cout << node->key << " ";
            inorder_walk(node->right);
        }
    }

    int get_subtree_depth(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(get_subtree_depth(node->left), get_subtree_depth(node->right));
    }

    
public:

    Node* root;
   
    BST() {
        root = nullptr;
    };

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

    void insert(T new_key) {
        Node* new_node = new Node(new_key);
        Node* x = root;
        Node* y = nullptr;

        while (x != nullptr) {
            y = x;
            if (new_key > x->key) {
                x = x->right;
            } else {
                x = x->left;
            }
        }

        if (y == nullptr) {
            root = new_node;
        } else if (new_key < y->key){
            y->left = new_node;
            new_node->parent = y;
        } else {
            y->right = new_node;
            new_node->parent = y;
        }
    }

    bool search(T key) {
        Node* current = root;
        
        while (current != nullptr) {
            if (current->key == key) {
                return true;
            } 

            if (key > current->key) {
                current = current->right;
            } else {
                current = current->left;
            }
        }

        return false;
    }

    void print() {
        Node* current = root;
        inorder_walk(current);
    }

    int find_diameter(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int left_diameter = find_diameter(node->left);
        int right_diameter = find_diameter(node->right);

        int root_diameter = this->get_subtree_depth(node->left) + this->get_subtree_depth(node->right) + 1;

        int arr[3] = {left_diameter, right_diameter, root_diameter};

        return *max_element(arr, arr + 3);
    }

};

int main() {
    int n; cin >> n;
    int num;

    BST<int> b;

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (!b.search(num)) {
            b.insert(num);
        }
    }

    cout << b.find_diameter(b.root);

}