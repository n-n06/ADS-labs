#include <iostream>

using namespace std;

const int MOD = 1e9 + 9;

int hash_rolling(string s) {
    int hash = 0;
    int pow = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        hash = (hash + (int)s.at(i) * pow) % MOD;
        pow = (MOD * pow) % MOD;
    }
    return hash;
}

int rabin_karp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    int count= 0;
    int target_hash = hash_rolling(pattern);

    int hash_i = 0;
    int pow = 1;
    int pow_store;

    for (int i = m - 1; i >= 0; i--) {
        pow_store = pow;
        hash_i = (hash_i + (int)text.at(i) * pow) % MOD;
        pow = (pow * MOD) % MOD;
    }

    if (hash_i == target_hash && text.substr(0, m) == pattern) {
        count++;
    }

    for (int i = 1; i <= n - m; i++) {
        hash_i = ((hash_i - ((int) text.at(i - 1) % MOD)) * pow_store * 128 % MOD + text.at(i + m - 1)) % MOD;
        if (hash_i == target_hash && text.substr(i, m) == pattern) {
            count++;
        }
    }

    return count;
}

int main() {
    string s; cin >> s;
    int n; cin >> n;   

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        cout << rabin_karp(s, s.substr(l - 1, r - l + 1)) << endl;
    } 


}