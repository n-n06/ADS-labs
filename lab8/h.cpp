#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

const long long int MOD = 1e15 + 9;
const int PRIME = 31;

long long count_substrings(string s) {
    unordered_map<long long, bool> substrings;
    for (long long i = 0; i < s.size(); i++) {
        long long hash = 0;
        for (long long j = i; j < s.size(); j++) {
            hash = (PRIME * hash + s[j]) % MOD;
            if (substrings.find(hash) == substrings.end()) {
                substrings[hash] = true;
            }
        }
    }
    return substrings.size();
}

int main() {
    int n; cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

}