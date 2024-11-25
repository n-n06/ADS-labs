#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    int graph[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int v1, v2;
    cin >> v1 >> v2;
    v1--; v2--;

    int path = 0;

    if (v1 == v2) {
        cout << 0;
        return 0;
    } 

    queue<int> q;
    q.push(v1);

    vector<bool> visited(n);
    visited[v1] = true;

    while (!q.empty()) {
        int u = q.front();
        path++;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[u][i] == 1) {
                if (i == v2) {
                    cout << path;
                    return 0;
                }
                visited[i] = true;
                q.push(i);
            }
        }
        q.pop();
    }
    cout << -1;

}