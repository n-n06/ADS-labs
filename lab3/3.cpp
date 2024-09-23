#include <iostream>
#include <algorithm>

using namespace std;

int patchwork_stacatto(const int* array, int n, int left, int right) {
    return upper_bound(array, array + n, right) - lower_bound(array, array + n, left);
}

int main() {
    int n; cin >> n;
    int array[n];

    int q; cin >> q;

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    sort(array, array + n);

    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int count1 = patchwork_stacatto(array, n, l1, r1);
        int count2 = patchwork_stacatto(array, n, l2, r2);

        int overlap = 0;

        if (r1 >= l2 && r2 >= l1) {
            overlap = patchwork_stacatto(array, n, max(l1, l2), min(r1, r2));
        }

        cout << count1 + count2 - overlap << endl;
    }

}