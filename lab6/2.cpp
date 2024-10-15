#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    int m; cin >> m;

    int arr1[n];
    int arr2[m];

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    int i, j;
    i = j = 0;

    int count = 0;
    vector <int> v;

    while (i < n && j < m) {
        if (arr1[i] > arr2[j]) {
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            v.push_back(arr1[i]);
            i++;
            j++;    
        }
    }

    for (int el : v) {
        cout << el << " ";
    }
    
}