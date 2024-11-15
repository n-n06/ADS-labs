#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

int max_str;

vector<int> pref_func(string prev, string next) {
    transform(next.begin(), next.end(), next.begin(), [](unsigned char c) {return tolower(c);});
    string s = next + "#" + prev;
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
    return pref;
}

bool pred(pair<string, int> p) {
    return p.second == max_str && p.second != 0;
}

int main() {
    string prev; cin >> prev;
    int n; cin >> n;
    string arr[n];

    max_str = 0;
    vector<pair<string, int>> entries;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        vector<int> pref_i = pref_func(prev, arr[i]);
        entries.push_back(pair<string, int>(arr[i], pref_i.back()));
        for (int j = 0; j < pref_i.size(); j++) {
            if (pref_i.back() > max_str) {
                max_str = pref_i.back();
            }
        }
    }
    int count = count_if(entries.begin(), entries.end(), pred);
    if (count == 0) {
        cout << count;
        return 0;
    }

    cout << count << endl;
    for (pair<string, int> p : entries) {
        if (p.second == max_str) {
            cout << p.first << endl;
        }
    }
    

}