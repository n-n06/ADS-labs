#include <iostream>

using namespace std;

bool binary_search(int* array, int n, int target) {
    int l = 0;
    int r = n - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (array[mid] == target) {
            return true;
        } else if (array[mid] > target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return false;
}

int main(){
    int n; cin >> n;
    int array[n];
    int k;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    cin >> k;

    if (k < array[0] || k > array[n - 1]) {
        cout << "No";
        return 0;
    }

    binary_search(array, n, k) ? cout << "Yes" : cout << "No";

    return 0;
}