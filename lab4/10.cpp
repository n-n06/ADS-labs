#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

void balance(vector<int>& arr, vector<int>& bst, int start, int end) {
    if (start > end) {
        return;
    }

    int mid = (start + end) / 2;
    int root = arr[mid];
    bst.push_back(root);

    balance(arr, bst, start, mid - 1);
    balance(arr, bst, mid + 1, end);
}


int main() {
    int n; cin >> n;
    int len = pow(2, n) - 1;
    int num;
    vector<int> v, bst;

    for (int i = 0; i < len; i++) {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    balance(v, bst, 0, len - 1);

    for (int i = 0; i < len; i++) {
        cout << bst[i] << " ";
    }
}