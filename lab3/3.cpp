#include <iostream>

using namespace std;


// int patchwork_stacatto(int* array, int l1, int r1, int l2, int r2, int n) {
//     int counter = 0;
//     for (int i = 0; i < n; i++) {
//         if ((array[i] >= l1 && array[i] <= r1) || (array[i] >= l2 && array[i] <= r2)) {
//             counter++;
//         }
//     }
//     return counter;
// } 



// int main() {
//     int n; int q;
//     int miku_array[n];
//     cin >> n >> q;

//     for (int i = 0; i < n; i++) {
//         cin >> miku_array[i];
//     }

//     for (int i = 0; i < q; i++) {
//         int l1, l2, r1, r2;
//         cin >> l1 >> l2 >> r1 >> r2;
//         cout << patchwork_stacatto(miku_array, l1, r1, l2, r2, n) << endl;
//     }

//     return 0;
// }