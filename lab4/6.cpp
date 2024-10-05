#include <iostream>
#include <stack>

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

    bool is_triangle(Node* node) {
        if (node == nullptr) {
            return false;
        } else {
            if (node->left != nullptr && node->right != nullptr) {
                return true;
            } else {
                return false;
            }
        }
    }

    Node* root;
    
public:
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

    void print() {
        Node* current = root;
        inorder_walk(current);
    }

    int get_triangles() {
        Node* current = root;
        stack <Node*> st;
        st.push(root);
        int trianlge_count = 0;

        while (!st.empty()) {
            Node* current = st.top();
            if (is_triangle(current)) {
                trianlge_count++;
            }
            st.pop();
            
            if (current->left != nullptr) {
                st.push(current->left);
            }

            if (current->right != nullptr) {
                st.push(current->right);
            }

        }

        return trianlge_count;
    }
};




int main() {
    int n; cin >> n;

    BST<int> b;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        b.insert(x);
    }

    cout << b.get_triangles();

    return 0;
}