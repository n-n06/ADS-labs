#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
const int MOD_VAL = 1e9 + 7; //define a constant

string hash_func(string s) {
    long long int h_sum = 0;
    long long int power11 = 1;

    for (int i = 0; i < s.size(); i++) {
        long long int chr = s.at(i) - 47;
        h_sum = (h_sum + chr * power11) % MOD_VAL;

        power11 = (power11 * 11) % MOD_VAL; //optimize power as in rolling polynomial hashing
    }

    return to_string(h_sum);
}

int main() {
    map <string, string> mp;
    map <string, bool> checked; 

    long long int n; cin >> n;
    vector <string> arr(2*n);

    for (long long int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
        mp[arr[i]] = hash_func(arr[i]);
    }

    int pair_count = 0;

    for (string s : arr) {
        if (pair_count == n) {
            break;
        }

        if (mp.find(mp[s]) != mp.end()) {
            cout << "Hash of string \"" << s <<"\" is " << mp[s] << endl;
            pair_count++;
        }
    }


}