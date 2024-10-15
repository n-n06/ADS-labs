#include <iostream>
#include <time.h>

using namespace std;

int partition(int* arr, int l, int r) {
    srand(time(NULL));

    int pivot = l + rand() % (r - l);
    swap(arr[r], arr[pivot]);

    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (arr[j] > arr[r]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);

    return i + 1;

}

void quickSort(int* arr, int l, int r) {
    if (l < r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main() {
    int n; cin >> n;
    int m; cin >> m;

    int arr[m][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[j][i];
        }
    }

    for (int i = 0; i < m; i++) {
        quickSort(arr[i], 0, n - 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}