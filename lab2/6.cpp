#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node(const int& num) : val(num), next(nullptr) {}
};

class LinkedList{
private:
    Node* head; //pointer to the head - initially set to nullptr
    int n; //number of nodes

public:

    //constructor
    LinkedList(int n) : head(nullptr), n(n) {}

    // destructor
    ~LinkedList(){
        Node* current = head;
        
        while (current != nullptr) {             
            Node* next = current->next;
            delete current;
            current = next;   
        }
    }
    
    // adding a new value
    void addValue(const int& num){
        Node* newNode = new Node(num);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    Node* insertValue(const int& pos, const int& val) {
        Node* current = head;
        Node* prev = nullptr;

        Node* newNode = new Node(val);
        if (pos == 0) {
            Node* temp = head;
            head = newNode;
            head->next = temp;
            return head;
        }

        for (int i = 0; i < pos; i++) {
            prev = current;
            current = current->next;
        }

        prev->next = newNode;
        newNode->next =  current;

        return head;
    }

};

int main() {
    int n, a; cin >> n;
    LinkedList list(n);

    for (int i = 0; i < n; i++) {
        cin >> a;
        list.addValue(a);
    }

    int value, position;
    cin >> value >> position;
    Node*  newHead = list.insertValue(position, value);
    while(newHead != nullptr) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }

}


