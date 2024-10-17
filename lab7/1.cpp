#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void merge(vector <string>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    string* l_arr = new string[n1];
    string* r_arr = new string [n2];

    for (int i = 0; i < n1; i++) {
        l_arr[i] = arr[l + i];
    }
    
    for (int i = 0; i < n2; i++) {
        r_arr[i] = arr[m + i + 1];
    }

    int i, j, k;
    i = j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (l_arr[i].length() <= r_arr[j].length()) {
            arr[k] = l_arr[i];
            i++;
        } else {
            arr[k] = r_arr[j];
            j++;
        }
        // } else {
        //     if (l_arr[i] <= r_arr[j]) {
        //         arr[k] = l_arr[i];
        //         i++;
        //     } else {
        //         arr[k] = r_arr[j];
        //         j++;
        //     }
        // }
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

void mergeSort(vector <string>& arr, int l, int r) {
    if (l < r) {
        int mid = (r + l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }

}

int main() {
    int n; cin >> n;
    string input;
    string word;

    cin.ignore();

    vector <string> arr;

    for (int i = 0; i < n; i++) {
        getline(cin, input);
        stringstream ss(input);

        while (ss >> word) {
            arr.push_back(word);
        }
        
        mergeSort(arr, 0, arr.size() - 1);

        for (const string& s : arr) {
            cout << s << " ";
        }
        cout << endl;
        arr.clear();
    }



}