#include <iostream>
#include <vector>
#include <set>

using namespace std;

int hash_rolling(string s, int p) {
    int h = 0;
    int pow = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        h = (h + (int)s.at(i) * pow) % p;
        pow = (pow * p) % p;
    }
    return h;
}

vector<int> rabin_karp(string text, string pattern, int p) {
    int n = text.length();
    int m = pattern.length();

    vector<int> positions;

    int target_hash = hash_rolling(pattern, p);

    int hash_i = 0;
    int pow = 1;
    int pow_store;

    for (int i = m - 1; i >= 0; i--) {
        pow_store = pow;
        hash_i = (hash_i + (int)text.at(i) * pow) % p;
        pow = (pow * p) % p;
    }
    
    if (hash_i == target_hash && text.substr(0, m) == pattern) {
        positions.push_back(0);
    }

    for (int i = 1; i <= n - m; i++) {
        hash_i = (((hash_i - ((int)text.at(i - 1)%p)) * pow_store) * 128 % p + text.at(i + m - 1)) % p;
        if (hash_i == target_hash) {
            if (text.substr(i, m) == pattern)
                positions.push_back(i);
        }
    }

    return positions;
}


int main() {
    string s; cin >> s;
    int n; cin >> n;

    set<int> coverage;

    string tapes[n];
    for (int i = 0; i < n; i++) {
        cin >> tapes[i];
        int m = tapes[i].length();
        for (int pos : rabin_karp(s, tapes[i], 1e9+9)) {
            for (int j = pos; j < pos + m; j++) {
                coverage.insert(j);
            }
        }
    }

    if (*coverage.begin() == 0 && *coverage.rbegin() == s.length() - 1 && coverage.size() == s.length()) {
        cout << "YES";
    } else {
        cout << "NO";
    }


}