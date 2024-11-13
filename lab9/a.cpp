#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> prefix_func(string text, string pattern) {
    string s = pattern + "空" + text;
    vector <int> pref (s.size());

    pref[0] = 0;

    int k;

    for (int i = 1; i < pref.size(); i++) {
        k = pref[i-1];
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
    string pass;
    string s;
    int k;
    cin >> pass >> k >> s;
    vector<int> pref = prefix_func(s, pass);
    int pos = kmp(pref, pass.size());
    if (pos >= k) {
        cout << "YES";
    } else {
        cout << "NO";
    }

}