#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    int adjMat[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            cin >> adjMat[i][j];
        }
    }

    int vert[n];
    
    for (int i = 0; i < n; i++) {
        cin >> vert[i];
        vert[i]--;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (adjMat[vert[j]][vert[k]] > adjMat[vert[j]][vert[i]] + adjMat[vert[i]][vert[k]]) {
                    adjMat[vert[j]][vert[k]] = adjMat[vert[j]][vert[i]] + adjMat[vert[i]][vert[k]];
                }
            }
        }

        int maxMin = 0;
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= i; k++) {
                maxMin = max(maxMin, adjMat[vert[j]][vert[k]]);
            }
        }
        cout << maxMin << endl;
    }

    

}


