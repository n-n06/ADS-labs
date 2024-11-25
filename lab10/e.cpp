#include <iostream>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    int jesse_we_need_to_cook[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> jesse_we_need_to_cook[i][j]; 
        }
    }

    for (int i = 0; i < q; i++) {
        int chem1, chem2, chem3;
        cin >> chem1 >> chem2 >> chem3;
        if (jesse_we_need_to_cook[chem1-1][chem2-1] &&
            jesse_we_need_to_cook[chem2-1][chem3-1] &&
            jesse_we_need_to_cook[chem3-1][chem1-1]) {
                cout << "YES" << endl;
            }
        else {
            cout << "NO" << endl;
        }
    }


}