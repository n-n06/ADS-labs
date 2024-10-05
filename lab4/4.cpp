#include <iostream>
#include <queue>
#include <vector>

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

    void dfs() {

        queue<Node*> q;
        Node* current = root;
        q.push(current);

        int layers = 0;
        vector <int> layerSums;

        while (!q.empty()) {
            int layerSum = 0;
            int layerSize = q.size();

            for (int i = 0; i < layerSize; i++) {
                current = q.front();
                q.pop();

                layerSum += current->key;

                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }
            layerSums.push_back(layerSum);
            layers++;
        }

        cout << layers << endl;
        for (int layerSum : layerSums) {
            cout << layerSum << " ";
        }
    }

    // void print() {
    //     inorder_walk(root);
    // }

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

    b.dfs();
}