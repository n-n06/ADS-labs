#include <iostream>
#include <string>

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

    Node* skipEveryOther() {
        Node* current = head;
        for (int i = 0; i < n / 2; i++) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            current = current->next;
        }
        return head;
    }
};

int main() {
    int n; cin >> n;
    int number;

    LinkedList list(n);

    for (int i = 0; i < n; i++) {
        cin >> number;
        list.addValue(number);
    }

    Node* newHead = list.skipEveryOther();
    
    Node* current = newHead;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }

}