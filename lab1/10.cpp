#include <iostream>
#include <sstream>
#include <string>
#include <deque>

using namespace std;

int main() {
    char ch;
    int number;

    string line = ""; //create an empty string
    deque<int> dq;
    stringstream ss; //create a stringstream

    while (line != "!") {
        getline(cin, line); //get each line into a string

        ss << line; //push the string to the stream
        ss >> ch; //pull out an element separated by space (in this case, a symbol)

        if (ch == '*') { 
            if (dq.size() < 1) { //check if not empty
                cout << "error" << endl;
            }
            else { //add front and back and pop them
                cout << dq.front() + dq.back() << endl;
                dq.pop_back(); 
                if (dq.size() > 0) {
                    dq.pop_front();
                }

            }
        } 
        else if (ch == '+') { //push front
            ss >> number;
            dq.push_front(number);
        } 
        else if (ch == '-') { //push back
            ss >> number;
            dq.push_back(number);
        }
        ss.clear(); //clear the stream so that we do not get accidental duplicates
        ch = ' '; //same for char
        number = 0; //same for number
    }   

}
