#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> pref_func(string text, string pattern) {
    string s = pattern + "#" + text + text;
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

    // for (int i =0 ; i < pref.size(); i++) {
    //     cout << pref[i] << " ";
    // }

    return pref;
}

int kmp(string text, string pattern) {
    vector<int> pref = pref_func(text, pattern);
    vector<int> pos;

    for (int i = 0; i < pref.size(); i++) {
        if (pref[i] == pattern.length()) {
            return i;
            cout << "found";
        }
    }
    return -1;
}

int main() {
    string s, t;
    cin >> s >> t;
    int pos = kmp(s, t);
    if (pos == -1) {
        cout << -1;
    } else {
        cout << s.size() - ( pos - s.size() - t.size());
    }


}