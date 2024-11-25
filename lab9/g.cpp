#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> prefix_func(string text) {
    string s = text;
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

// int kmp(string text, string pattern) {
//     vector<int> pref = prefix_func(text, pattern);
//     int pattern_size = pattern.size();
//     int pos = 0;
//     for (int i = 0; i < pref.size(); i++) {
//         if (pref[i] == pattern_size) {
//             return true;
//         }
//     }
//     return false;
// }

int main() {
    string s; cin >> s;
    vector<int> pref = prefix_func(s);
    cout << s.size() - pref.back();

}