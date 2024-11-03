#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define MOD_VAL 1000000007; //define a constant

long long int hash_func(string s) {
    long long int h_sum = 0;
    long long int power11 = 1;

    for (int i = 0; i < s.size(); i++) {
        long long int chr = s.at(i) - 47;
        h_sum = (h_sum + chr * power11) % MOD_VAL;

        power11 = (power11 * 11) % MOD_VAL; //optimize power as in rolling polynomial hashing
    }

    return h_sum;
}

int main() {
    map <string, long long int> mp;

    long long int n; cin >> n;
    vector <string> arr(2*n);

    for (long long int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
        mp[arr[i]] = hash_func(arr[i]);
    }

    for (string s : arr) {
        vector<string>::iterator pos = find(arr.begin(), arr.end(), to_string(mp[s]));
        if (pos != arr.end()) {
            cout << "Hash of string \"" << s << "\" is " << mp[s] << endl;
        }
    }
}