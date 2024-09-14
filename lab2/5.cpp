#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<string>* studentStack) {
    cout << "Students: " << endl;
    while (!studentStack->empty()) {
        cout << studentStack->top() << endl;
        studentStack->pop();
    }
}

int main() {
    stack<string> studentStack;
    int n; cin >> n;
    string name;
    for (int i = 0; i < n; i++) {
        cin >> name;
        if (studentStack.empty() || studentStack.top() != name) {
            studentStack.push(name);
        }
    }
    cout << "All in all: " << studentStack.size() << endl;
    printStack(&studentStack);

    return 0;
}