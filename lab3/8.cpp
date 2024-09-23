#include <iostream>

using namespace std;

int binary_search(int* array, int n, int k) {
    int l = 0;
    int r = n-1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (k == array[mid]) {
            return mid + 1;
        }
        if (k > array[mid]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l + 1;
}

int main() {
    int n, m; cin >> n >> m;
    int array[n];
    int range_end[n];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
        if (i == 0) {
            range_end[i] = array[i];
        } else {
            range_end[i] = array[i] + range_end[i - 1];
        }
    }

    int error;

    for (int i = 0; i < m; i++) {
        cin >> error;
        cout << binary_search(range_end, n, error) << endl;
    }

    return 0;
}