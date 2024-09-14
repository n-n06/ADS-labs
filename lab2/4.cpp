#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> intPair;

struct Node {
    int val;
    Node* next;

    Node(const int& num) : val(num), next(nullptr) {}
};

class LinkedList{
private:
    Node* head;
    int n; 
    map<int, int> frequencies;

    vector<intPair> sortByValues() {
        vector<intPair> freqVector(frequencies.begin(), frequencies.end());

        sort(freqVector.begin(), freqVector.end(), [](const intPair& a, const intPair& b) {
            return a.second == b.second ? a.first > b.first : a.second > b.second;
        });
        return freqVector;
    }


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
        frequencies[num] += 1;

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

    vector<int> getMode() {
        vector<intPair> freqVector = sortByValues(); 
        vector<int> modes = {freqVector[0].first};
        for (int i = i; i < freqVector.size(); i++) {
            if (freqVector[i].second == freqVector[0].second && freqVector[0].first != freqVector[i].first) {
                modes.push_back(freqVector[i].first);
            }
        }
        return modes;
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

    vector<int> modes = list.getMode();
    for (int i : modes) {
        cout << i << " ";
    }
}