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

vector<int> kmp(vector<int> pref, int pattern_size) {
    vector<int> pos;
    for (int i = 0; i < pref.size(); i++) {
        if (pref[i] == pattern_size) {
            pos.push_back(i - 2 * pattern_size - 1);
        }
    }
    return pos;
}

int main() {
    string s1; string s2;
    cin >> s1 >> s2;
    vector<int> pos = kmp(prefix_func(s1,s2), s2.size());
    cout << pos.size() << endl;
    for (int i : pos) {
        cout << i << " ";
    }
}