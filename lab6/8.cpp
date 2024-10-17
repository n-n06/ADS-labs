#include <iostream>

using namespace std;

char bin_search(char* arr, int n, char target) {
    int l = 0;
    int r = n - 1;

    int mid = (r + l) / 2;

    if (target <= arr[0] || target >= arr[r]) {
        return arr[0];
    } 


    while (l < r) {
        if (arr[mid] == target) {
            return arr[mid+1];
        } else if (arr[mid] > target){
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
}

int main() {
    int n; cin >> n;
    char arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    char target; cin >> target;

    cout << bin_search(arr, n, target);
}