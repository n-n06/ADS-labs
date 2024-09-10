#include <iostream>
#include <stack>

using namespace std;

bool compareStacks(stack<char> st1, stack<char> st2) {
    //comparing stacks element by element
    char element1;
    char element2;
    while (!st1.empty()) {
        element1 = st1.top();
        st1.pop();
        if (!st2.empty()) { //check if we can even check :)
            element2 = st2.top();
            st2.pop();
        }

        if (element1 != element2) {
            return false;
        }
    }
    return st2.empty();
}

int main() {
    char ch;
    stack <char> st1;
    stack <char> st2;

    while (cin.get(ch) && ch != ' ') {
        if (ch == '#') {
            st1.pop();
        } else {
            st1.push(ch);
        }
    }
    
    while (cin.get(ch) && (ch != '\n') && (ch != ' ')) {
        if (ch == '#') {
            st2.pop();
        }
        else {
            st2.push(ch);
        }
    }

    (compareStacks(st1, st2)) ? cout << "Yes" : cout << "No";

}