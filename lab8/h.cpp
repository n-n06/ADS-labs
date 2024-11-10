#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

const long long PRIME = 31;

long long hash_func(string s) {
    long long h = 0;
    for (int i = 0; i < s.length(); i++) {
        h = (h * PRIME + (s[i] - 'a' + 1));
    }
    return h;
}

bool rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    int text_hash = hash_func(text.substr(0, m));
    int pattern_hash = hash_func(pattern);

    int prime = 1;
    for (int i = 0; i < m - 1; i++) {
        prime *= PRIME;
    }

    for (int i = 0; i <= n - m; i++) {
        if (text_hash == pattern_hash) {
            return true;
        }
        if (i < n - m) {
            text_hash = (text_hash - prime * (text[i] - 'a' + 1)) * PRIME + (text[i + m] - 'a' + 1);
        }
    }
    return false;
}


int main() {
    int n; cin >> n;
    string arr[n];

    int min_size = 1e5;
    string min_string;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (min_size > s.length()) {
            min_size = s.length();
            min_string = s;
        }
        arr[i] = s;
    }

    int max_size = 0;
    string lcs = "";

    for (int i = 0; i < min_size; i++) {
        for (int j = 1; j <= min_size - i; j++) {
            string substr = min_string.substr(i, j);
            bool flag = true;

            for (int k = 0; k < n; k++) {
                if (!rabinKarp(arr[k], substr)) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                if (max_size < substr.length()) {
                    max_size = substr.length();
                    lcs = substr;
                }
            }
        }
    }

    cout << lcs;
}