#include <iostream>
#include <string>
#include <vector>

using namespace std;

int kmp(vector<int> pref, int pattern_size) {
    int pos = 0;
    for (int i = 0; i < pref.size(); i++) {
        if (pref[i] == pattern_size) {
            pos++;
        }
    }
    return pos;
}

int pref_func(string pattern, int n) {
    string s = pattern + "#" + pattern;
    vector<int> pref(s.size());

    pref[0] = 0;
    int k;

    while (kmp(pref, pattern.size()) < n) {

        for (int i = 1; i < pref.size(); i++) {
            k = pref[i - 1];
            while (k > 0) {
                if (s[i] == s[k]) {
                    k++;
                    break;
                }
                k = pref[k - 1];
            }
            if (k % pattern.size() == 0 && s[i] == s[k]) {
                k = 1;
            }
            pref[i] = k;
        }
        if (k != 0) {
            
        }
        s += pattern;
        pref.resize(pref.size() + pattern.size());
    }

    for (int i : pref) {
        cout << i << ' ';
    }

    for (int i = pref.size() - 1; i >= 0; i--) {
        if (pref[i] != 0) {
            return i + 1;
        }
    }
    return 0;
}



int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int k; cin >> k;
        cout << pref_func(s, k) - s.size() - 1 << endl;
    }
}