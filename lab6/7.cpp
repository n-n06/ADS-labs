#include <iostream>
#include <time.h>
#include <climits>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n; cin >> n;
    map <string, string> m;
    map <string, string> rev_m;

    for (int i = 0; i < n; i++) {
        string old_nick, new_nick;
        cin >> old_nick >> new_nick;

        // a -> b -> c
        // m[a] = b, rev[b] = a

        if (rev_m.find(old_nick) != rev_m.end()) {
            m[rev_m[old_nick]] = new_nick;
            rev_m[new_nick] = rev_m[old_nick];
            rev_m.erase(old_nick);
        } else {
            m[old_nick] = new_nick;
            rev_m[new_nick] = old_nick;
        }
    }

    vector<pair<string, string>> v;

    cout << m.size() << endl;

    for (auto& p : m) {
        cout << p.first << " " << p.second << endl;
    }


}