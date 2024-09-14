#include<iostream>

using  namespace std;


class LinkedList {
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(string data) {
        Node *current = new Node(data);
        if (head == nullptr) {
            head = tail = current;
        } else {
            tail->pNext = current;
            tail = current;
        }
    }

    void pop_front() {
        Node *temp = head;
        head = head->pNext;
        delete temp;
    }

    void shift(int k) {
        while (k--) {
            push_back(head->data);
            pop_front();
        }
    }

    void print() {
        Node *current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->pNext;
        }
        cout << endl;
    } 

private:
    class Node {
    public:
        Node *pNext;
        string data;

        Node(string data = string(), Node *pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };

    Node *head;
    Node *tail;
};

int main() {
    int n, k;
    cin >> n >> k;

    LinkedList list;
    for (int i = 0; i < n; i++) {
        string data;
        cin >> data;
        list.push_back(data);
    }

    list.shift(k);

    list.print();

    return 0;
}
