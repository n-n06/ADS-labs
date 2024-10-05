#include <iostream>

using namespace std;

struct Node {
	int data;
    int count;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
        this->count = 1;
		left = nullptr;
		right = nullptr;
	} 
};

Node* getMin(Node* root) {
	while (root->left != nullptr) {
		root = root->left;
	}
	return root;
}

Node* add(Node* root, int data) {
	if (root == nullptr) {
		return new Node(data);
	} else if (root->data == data ) {
        root->count += 1;
    } else if (root->data > data) {
		if (root->left == nullptr) {
			root->left = new Node(data);
		} else {
			root->left = add(root->left, data);
		}
	} else if (root->data < data) {
		if (root->right == nullptr) {
			root->right = new Node(data);
		} else {
			root->right = add(root->right, data);
		}
	}
	return root;
}

Node* deleteNode(Node* root, int data) {
	if (root == nullptr) {
		return nullptr;
	} else if (root->data > data) {
		root->left = deleteNode(root->left, data);
		return root;
	} else if (root->data < data) {
		root->right = deleteNode(root->right, data);
		return root;
	} else if (root->count == 0) {
		if (root->left == nullptr && root->right == nullptr) {
			delete root;
			return nullptr;
		} else if (root->right == nullptr) {
			Node* temp = root->left;
			delete root;
			return temp;
		} else if (root->left == nullptr) {
			Node* temp = root->right;
			delete root;
			return temp;
		} else {
			Node* temp = getMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
			return root;
		}
	} else {
        root->count -= 1;
        return root;
    }
}

Node* find(Node* root, int x) {
	if (root == nullptr) {
		return nullptr;
	} else if (root->data == x) {
		return root;
	} else if (root->data < x) {
		return find(root->right, x);
	} else {
		return find(root->left, x);
	}
}

int main() {
    int n; cin >> n;
    Node* root = nullptr;
    string s; int data;

    for (int i = 0; i < n; i++) {
        cin >> s >> data;
        if (s == "insert") {
            root = add(root, data);
        } else if (s == "delete") {
            deleteNode(root, data);
        } else if (s == "cnt") {
            Node* node = find(root, data);
            if (node != nullptr) {
                cout << node->count << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
}