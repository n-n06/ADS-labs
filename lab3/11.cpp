#include <iostream>
#include <climits>

using namespace std;

int min_length_subarray(int array[], int n, int target) {
    int l = 0;
    int sum = 0;
    int min_length = INT_MAX;

    for (int i = 0; i < n; i++) {
        sum += array[i];

        while (sum >= target) {
            min_length = min(min_length, i - l + 1);
            sum -= array[l];
            l++;
        }
    }

    return min_length;
}

int main() {
    int n, target; cin >> n >> target;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << min_length_subarray(arr, n, target);
}