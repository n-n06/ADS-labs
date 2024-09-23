#include <iostream>
#include <algorithm>

using namespace std;

// int binary_search(int* array, int n, int target) {
//     int l = 0;
//     int r = n - 1;

//     while (l <= r) {
//         int mid = (r + l) / 2;
//         if (array[mid])
//     }
// }

int main(){
    int n; cin >> n;
    int k; cin >> k;

    int arr_of_max[n];

    int max_coord = -1;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        arr_of_max[i] = max({x1,x2,y1,y2});
        max_coord = max(max_coord, arr_of_max[i]);
    }

    sort(arr_of_max, arr_of_max + n);

    cout << arr_of_max[k - 1];
}