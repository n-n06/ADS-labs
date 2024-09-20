#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_partition(const long int* array, long int n, long int mid, long int k) {
    long int counter = 1, sum = 0;

    for (long int i = 0; i < n; i++) {
        sum += array[i];
        if (sum > mid) {
            counter++;
            if (counter > k) {
                return false;
            }
            sum = array[i];
        }
    }

    return true;
}

int main() {
    long int n, k;
    cin >> n >> k;

    long int ghoul_sum = 0;

    long int ghoul_array[n];

    for (long int i = 0; i < n; i++) {
        cin >> ghoul_array[i];
        ghoul_sum += ghoul_array[i];
    }

    long int l = *max_element(ghoul_array, ghoul_array + n);
    long int r = ghoul_sum;
    
    long int min_pos_max = ghoul_sum;

    while (l <= r) {
        long int mid = (l + r) / 2;

        if (can_partition(ghoul_array, n, mid, k)) {
            min_pos_max = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << min_pos_max;

    return 0;
}