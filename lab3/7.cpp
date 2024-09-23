#include <iostream>
#include <algorithm>

using namespace std;

bool can_deliver(int* array, int n, int f, int max) {
    int flights = 0;
    for (int i = 0; i < n; i++) {
        flights += (array[i] + max - 1) / max;
    }
    return flights <= f;
}

int main() {
    int n; cin >> n;
    int f; cin >> f;

    int array[n];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int l = 1;
    int r = *max_element(array, array + n);

    int min_capacity = l;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (can_deliver(array, n, f, mid)) {
            r = mid - 1;
            min_capacity = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << min_capacity;
}