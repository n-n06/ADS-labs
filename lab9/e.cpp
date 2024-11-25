#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> pref_func(string pattern, int n) {
    string s = pattern;
    vector<int> pref(s.size());

    pref[0] = 0;
    int k;

    for (int i = 1; i < pref.size(); i++) {
        k = pref[i - 1];
        while (k > 0) {
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


    // for (int i : pref) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    return pref;
}


int kmp(vector<int> pref, int pattern_size) {
    int pos = 0;
    for (int i = 0; i < pref.size(); i++) {
        if (pref[i] == pattern_size) {
            pos++;
        }
    }
    return pos;
}




int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int k; cin >> k;
        vector<int> v = pref_func(s, k);
        if (v.back() == 0) {
            cout << s.size() * k;
        } else {
            cout << (s.size() - v.back()) * k + v.back();
        }
        cout << endl;
    }
}