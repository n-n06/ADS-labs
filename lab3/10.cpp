#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int n;
    int h;
    int* gold;

    bool possible(int gold_per_h) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (gold[i] + gold_per_h - 1) / gold_per_h;
        }
        return sum <= h;
    }

public:
    Solution(int n, int h, int* array) : n(n), h(h), gold(array) {};

    int binary_search() {
        int l = 1;
        int r = *max_element(gold, gold + n);
        int k = r;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (possible(mid)) {
                k =  mid;
                r = mid - 1;
            } else  {
                l = mid + 1;
            }
        }
        return k;
    }
};

int main() {
    int n, h;

    cin >> n >> h;
    int gold[n];

    for (int i = 0; i < n; i++) {
        cin >> gold[i];
    }

    Solution s = Solution(n, h, gold);
    cout << s.binary_search();

}