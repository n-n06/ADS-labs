#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INT32_MAX 2147483647
using namespace std;

vector<vector<int>> edges(100000);

int bfs(int s, int n) {
    vector<long long int> dist;
    dist.resize(n);
    for(int i = 0; i < n; i++){
        dist[i] = (long long) INT32_MAX;
    }

    queue<int> q;
    q.push(s);
    dist[s] = 0;
    
    while(!q.empty()){
        int current = q.front(); q.pop();
        for(int j : edges[current]){
            if (dist[j] == (long long) INT32_MAX){
                dist[j] = dist[current]+1;
                q.push(j);
            }
        }
    }
    if (dist[n - 1] == (long long) INT32_MAX) {
        return -1;
    }
    return dist[n - 1];
}

int main() {
    int n, m;
    cin >> n >> m;
    int graph[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    bool flag = graph[0][n-1] == 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n ;j ++) {
            if (i != j) {
                if (graph[i][j] == 0) {
                    if (!(flag)) {
                        edges[i].push_back(j);
                    }
                } else if (flag) {
                    edges[i].push_back(j);
                }
            }
        }
    }
    cout << bfs(0, n);


}
