#include <iostream>
#include <time.h>
#include <climits>
#include <vector>

using namespace std;

int partition(long int* arr, int l, int r) {
    srand(time(NULL));

    int i = l - 1;

    int pivot;
    pivot = l + rand() % (r - l);
    
    swap(arr[pivot], arr[r]);

    for (int j = l; j < r; j++) {
        if (arr[j] <= arr[r]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[r]);

    return i + 1;

}

void quickSort(long int* arr, int l, int r) {
    if (l < r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main() {

    int n; cin >> n;
    long int num;
    long int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);


    vector <pair<long int, long int>> v;

    long int diff = LONG_MAX;
    for (int i = 0; i < n - 1; i++) {
        int currentDiff = abs(arr[i] - arr[i + 1]);
        if (currentDiff < diff) {
            diff = currentDiff;
            v.clear();
            v.push_back(pair<long int , long int>(arr[i], arr[i + 1]));
        } else if (currentDiff == diff) {
            v.push_back(pair<long int , long int>(arr[i], arr[i + 1]));
        } 
    }

    for (auto p : v) {
        cout << p.first << " " << p.second << " ";
    }
}