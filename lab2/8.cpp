#include <bits/stdc++.h>
  
using namespace std;

struct Node{
	Node * prev;
	Node * next;
	string val;
	Node(string _val){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt;

void add_back(string s){
    Node* new_node = new Node(s);
    new_node->next = NULL;

    Node* temp = tail;
    tail = new_node;

    if (head == NULL) {
        head = new_node;
    } else {
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void add_front(string s){
    Node* new_node = new Node(s);
    new_node->next = head;
    if (head != NULL) {
        head->prev = new_node;
    } else {
		tail = new_node;
	}
    head = new_node;
    new_node->prev = NULL;
}

bool empty(){
    return (head == NULL);
}
void erase_front(){
    if (head == tail) {
        delete head;
        head = tail = NULL;
    } else {
		Node* temp = head->next;
        temp->prev = head->prev;
		head = temp;
    }
}
void erase_back(){
    if (head == tail) {
        delete head;
        head = tail = NULL;
    } else {
        Node* temp = tail->prev;
        temp->next = tail->next;
        tail = temp;
    }
}
string front(){
    return head->val;
}
string back(){
    return tail->val;
}
void clear(){
    while (head != NULL) {             
        Node* next = head->next;
        delete head;
        head = next;   
    }
	delete head;
}
  
int main()
{
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
   		// cout << "hi" << endl;
   	}
    return 0;
}