#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int prime = 31;
const int mod = 1e9 + 9;

bool comp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

int rabinKarpAlgo(const string& pattern, const string& text) {
    int n = text.size();
    int m = pattern.size();

    vector<long long> powers(max(n, m));
    powers[0] = 1;
    for (int i = 1; i < (int)powers.size(); i++) {
        powers[i] = (powers[i - 1] * prime) % mod;
    }

    vector<long long> hashCodes(n+1, 0);
    for (int i = 0; i < n; i++) {
        hashCodes[i+1] = (hashCodes[i] + (text[i] - 'a' + 1) * powers[i]) % mod;
    }

    long long hashOfPattern = 0;
    for (int i = 0; i < m; i++) {
        hashOfPattern = (hashOfPattern + (pattern[i] - 'a' + 1) * powers[i]) % mod;
    }
    int occurences = 0;


    for (int i = 0; i <= n - m; i++) {
        long long currentHash = (hashCodes[i + m] + mod - hashCodes[i]) % mod;
        if (currentHash == hashOfPattern * powers[i] % mod) {
            occurences++;
        }
    }

    return occurences;
}

int main() {
    int n; cin >> n;
    while (n != 0) {
        vector <pair<string, int>> v;

        string patterns[n];
        string text;
        for (int i = 0; i < n; i++) {
            cin >> patterns[i];
        } 
        cin >> text;

        for (int i = 0; i < n; i++) {
            pair<string, int> p;
            p.first = patterns[i];
            p.second = rabinKarpAlgo(patterns[i], text);
            v.push_back(p);
        }

        sort(v.begin(), v.end(), comp);

        int max = v[0].second;
        cout << max << endl;
        for (int i = 0; i < n; i++) {
            if (v[i].second != max) {
                break;
            }
            cout << v[i].first << endl;
        }

        cin >> n;

    }

}