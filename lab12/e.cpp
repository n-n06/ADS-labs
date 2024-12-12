#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n; cin >> n;
    int graph[n][n];
    vector<pair<pair<int,int>, int>> edges;
    int parent[n];

    for (int i = 0; i < n;i ++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 100000) {
                graph[i][j] = 0;
            } else {
                edges.push_back({{i,j}, graph[i][j]});
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (auto edge : edges) {
            if v.d > u.d  + w(u,v):
		    v.d = u.d + w(u,v)
		v.pi = u
        }
    }
}