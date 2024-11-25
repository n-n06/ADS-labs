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

int kmp(string text, string pattern) {
    vector<int> pref = prefix_func(text, pattern);
    int pattern_size = pattern.size();
    int pos = 0;
    for (int i = 0; i < pref.size(); i++) {
        if (pref[i] == pattern_size) {
            return true;
        }
    }
    return false;
}

int main() {
    string a, b;
    cin >> a >> b;
    string a_ext = "";
    int times = 0;

    if (a.size() >= b.size()) {
        if (kmp(a, b)) {
            cout << 1;
        } else {
            cout << -1;
        }
    } else {
        while (a_ext.size() < b.size()) {
            a_ext += a;
            times++;
        }
        if (kmp(a_ext, b)) {
            cout << times;
        } else {
            times++;
            a_ext += a;
            if (kmp(a_ext, b)) {
                cout << times;
            } else {
                cout << -1;
            }
        }
    }
}