#include <iostream>

using namespace std;

int binary_search_inc(int array[], int n, int k) {
    int l = 0;
    int r = n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (array[mid] == k) {
            return mid;
        } else if (array[mid] > k) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return -1;
}

int binary_search_dec(int array[], int n, int k) {
    int l = 0;
    int r = n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (array[mid] == k) {
            return mid;
        } else if (array[mid] > k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return -1;
}

int main() {
    int t; cin >> t;
    int tests[t];

    for (int i = 0; i < t; i++) {
        cin >> tests[i];
    }

    int n, m;
    cin >> n >> m;

    int array[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> array[i][j];
        }
    }

    int y;

    for (int i = 0; i < t; i++) {
        for (int x = 0; x < n; x++) {
            if (x % 2 != 0) {
                y = binary_search_inc(array[x], m, tests[i]);
            } else {
                y = binary_search_dec(array[x], m, tests[i]);
            }

            if (y != -1) {
                cout << x << " " << y << endl;
                break;
            }
        }

        if (y == -1) {
            cout << -1 << endl;
        }
    }


    return 0;
}