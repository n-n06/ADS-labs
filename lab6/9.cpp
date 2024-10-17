#include <iostream>
#include <cstring>

using namespace std;

void merge(char* arr, int l, int m, int r) {
    int n1 = m - l + 2;
    int n2 = r - m + 1;

    char* l_arr = new char[n1];
    char* r_arr = new char[n1];
    
    for (int i = 0; i < n1 - 1; i++) {
        l_arr[i] = arr[l + i];
    }

    for (int i = 0; i < n2 - 1; i++) {
        r_arr[i] = arr[m + i + 1];
    }

    l_arr[n1 - 1] = '}';
    r_arr[n2 - 1] = '}';

    int i, j;
    i = j = 0;
    int k = l;

    while (k <= r) {
        if (l_arr[i] < r_arr[j]) {
            arr[k] = l_arr[i];
            i++;
        } else {
            arr[k] = r_arr[j];
            j++;
        }
        k++;
    }
    delete[] l_arr;
    delete[] r_arr;


}

void mergeSort(char* arr, int l, int r) {
    if (l < r) {
        int m = (r + l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


int main() {
    char* str = new char[10000];//alloacte enough memory (i know this is a bad idea)

    cin.getline(str, 10000);    //get the string

    int n = strlen(str);
    char* arr = new char[strlen(str) + 1];
    strcpy(arr, str);   //now we have the string as an array of chars
    delete[] str;

    mergeSort(arr, 0, n - 1);
    cout << arr << endl;

    delete[] arr;
}