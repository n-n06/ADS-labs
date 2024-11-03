#include <iostream>
#include <math.h>

using namespace std;
using ll = long long int;

char dehash(ll letter, ll& prev, int pos) {
    ll this_letter = letter - prev;
    this_letter /= pow(2, pos);
    prev = letter;
    return (char) (97 + this_letter);
}

int main() {
    int n; cin >> n;
    ll prev = 0;
    ll arr[n];

    string s ;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s += dehash(arr[i], prev, i);
    }

    cout << s;


}