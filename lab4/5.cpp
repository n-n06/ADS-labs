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
        int size;


        void insert(Node* current, int parent, int child, int direction) {
            if (current != nullptr) {
                current = search(current, parent);
                Node* temp = new Node(child);
                if (direction == 0) {
                    current->left = temp; 
                    size++;
                }
                else if (direction == 1) {
                    current->right = temp; 
                    size;
                } 
            }
        }

        Node* search(Node* current, int key) {
            if (current == nullptr) {
                return nullptr;
            }
            if (current->key == key) {
                return current;
            }
            Node* leftSearch = search(current->left, key);
            if (leftSearch != nullptr) {
                return leftSearch;
            }
            return search(current->right, key);
        }

        int get_height(Node* current) {
            if (current == nullptr) { 
                return 0;
            }
            return 1 + max(get_height(current->left), get_height(current->right));
        }

        int calculate_width(Node* current, int level) {
            if (current == nullptr) {
                return 0;
            }
            if (level == 1) {
                return 1;
            }
            return calculate_width(current->left, level - 1) + calculate_width(current->right, level - 1);
        }

        int get_max_width(Node* current) {
            int max_width = 0;
            int h = get_height(current);
            
            for (int i = 1; i <= h; i++) {
                int width = calculate_width(current, i);
                if (width > max_width) 
                    max_width = width;
            }
            return max_width;
        }

    public:
        BST() {
            root = nullptr;
        };

        void insert(int parent, int child, int direction) {
            if (root == nullptr) {
                root = new Node(parent); 
                size++;
            }
            return insert(root, parent, child, direction);
        }

        bool search(int key) {
            return search(root, key) != nullptr;
        }


        int get_width() {
            return get_max_width(root);
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
        int x, y, z;

        BST b;

        for (int i = 0; i < n - 1; i++) {
            cin >> x >> y >> z;
            b.insert(x, y, z);
        }

        cout << b.get_width();
    }