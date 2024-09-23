#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> fight_club(int* array, int n, int power) {
    pair<int,int> ans;

    auto it = upper_bound(array, array + n, power);

    ans.first = it - array;
    int sum = 0;

    for (auto iter = array; iter != it; iter++) {
        sum += *iter;
    }
    ans.second = sum;
    return ans;
}

int main() {
    int n; cin >> n;
    int fighters[n];
    for (int i = 0; i < n; i++) {
        cin >> fighters[i];
    }
    sort(fighters, fighters + n);

    int p, power; cin >> p;
    for (int i = 0; i < p; i++) {
        cin >> power;
        pair<int, int> fc = fight_club(fighters, n, power);
        cout << fc.first << " " << fc.second << endl;
    }
    return 0;
}