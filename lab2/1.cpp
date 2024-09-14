#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int a[n];

    int offset = 0;
    int dist = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k; cin >> k;

    for (int i = 0; i < n; i++) {
        if (abs(a[i] - k) < dist || dist < 0 ) {
            offset = i; dist = abs(a[i] - k);
        }
    }
    cout << offset;

}