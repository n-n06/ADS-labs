#include <iostream>
#include <numeric>

using namespace std;

bool comp(int* a, int* b, int m) {
    int sum_a = accumulate(a, a + m, 0);
    int sum_b = accumulate(b, b + m, 0);

    if (sum_a == sum_b) {
        for (int i = 0; i < m; i++) {
            if (a[i] == b[i]) {
                continue;
            } else {
                return a[i] < b[i];
            }
        }
    } else {
        return sum_a > sum_b;
    }

    return true;
}

void merge(int** arr, int l, int mid, int r, int m) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int** l_arr = new int*[n1];
    int** r_arr = new int*[n2];

    for (int i = 0; i < n1; i++) {
        l_arr[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++) {
        r_arr[i] = arr[mid + i + 1];
    }

    int i, j, k;
    i = j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (comp(l_arr[i], r_arr[j], m)) {
            arr[k] = l_arr[i];
            i++;
        } else {
            arr[k] = r_arr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = l_arr[i];
        i++; 
        k++;
    }

    while (j < n2) {
        arr[k] = r_arr[j];
        j++;
        k++;
    }


    delete[] l_arr;
    delete[] r_arr;
}

void mergeSort(int** arr, int l, int r, int m) {
    if (l < r) {
        int mid = (r + l) / 2;
        mergeSort(arr, l, mid, m);
        mergeSort(arr, mid + 1, r, m);

        merge(arr, l, mid, r, m);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    mergeSort(arr, 0, n - 1, m);

    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }

    delete[] arr;
}