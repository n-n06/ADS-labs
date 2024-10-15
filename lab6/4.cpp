#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

bool comp(int* a, int* b) { //comparing dates
    for (int i = 2; i >= 0; i--) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return false; 
}


int* toArray(const string &str, char delim) {
    stringstream ss(str);
    string temp;

    int* result = new int[3];

    int index = 0;
    //we spit out strings from our string stream delimited by - 
    while (getline(ss, temp, delim) && index < 3) {
        result[index] = stoi(temp); //convert numbers to ints
        index++;
    }

    return result; //return the arrays of dates
}
int main() {
    int n; cin >> n;
    string date;
    char delim = '-';

    vector <int*> v; //vector of dates

    for (int i = 0; i < n; i++) {
        cin >> date;
        v.push_back(toArray(date, delim));
    }

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++) {
        //setfill is to fill in the gaps and setw to output everything as a 3 digit number like 01
        cout << setfill('0') << setw(2) <<  v[i][0] << "-" << setfill('0') << setw(2) << v[i][1] << "-" << v[i][2] << endl;
        delete[] v[i];
    }

}