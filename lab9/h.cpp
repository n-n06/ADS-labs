#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> prefix_func(string s) {
    vector<int> pref(s.size());
    pref[0] = 0;

    int k;

    for (int i = 1; i < pref.size(); i++) {
        k = pref[i - 1];
        while(k > 0) {
            if (s[i] == s[k]) {
                k++;
                break;
            }
            k = pref[k - 1];
        }
        if (k == 0 && s[i] == s[k]) {
            k = 1;
        }

        pref[i] = k;
    }

    return pref;
}

int main() {
    string s; cin >> s;
    vector<int> pref = prefix_func(s);
    // for (int i : pref) {
    //     cout << i << " ";
    // }

    int count = 0;
    for (int i = 1; i < pref.size(); i++) {
        if (i % 2 == 0) {
            int val = i - pref[i - 1];
            if ((i / val) % 2 == 0) {
                count++;
            }
        }
    }
    cout << count;
}