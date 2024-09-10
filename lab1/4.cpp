#include <iostream>
#include <stack>

using namespace std;

int main() {
    char ch;
    char top;
    stack <char> st;

    while (cin.get(ch) && (ch != '\n')) {
        if (st.empty()) {
            st.push(ch);
        } else {
            if (ch == st.top()) {
                st.pop();
                continue; 
            }
            st.push(ch);
        }
    }

    (st.empty()) ? cout << "YES" : cout << "NO";

    return 0;
}