#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

int main() {
    int n; cin >> n;
    int weight;
    vector<pair<pair<int,int>, int>> edges;
    int parent[n];
    long long int dist[n];

    for (int i = 0; i < n;i ++) {
        for (int j = 0; j < n; j++) {
            cin >> weight;
            if (weight != 100000) {
                edges.push_back({{i,j}, weight});
            }
        }
        dist[i] = INT32_MAX;
        parent[i] = -1;
    }

    dist[0] = 0;

    vector<int> cycle;
    int cycle_start;

    for (int i = 0; i < n; i++) {
        cycle_start = -1;
        for (pair<pair<int,int>, int> edge : edges) {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = max(dist[u] + w, (long long) - (long long) INT32_MAX);
                parent[v] = u;
                cycle_start = v;
            }
        }
    }

    if (cycle_start == -1) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;

    for (int i = 0; i < n; i++) {
        cycle_start = parent[cycle_start];
    }

    for (int v = cycle_start; ; v = parent[v]) {
        cycle.push_back(v + 1);
        if (v == cycle_start && cycle.size() > 1) break;
    }

    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << endl;
    for (int v : cycle) {
        cout << v << " ";
    }
    

}