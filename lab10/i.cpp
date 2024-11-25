#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int size;
    vector<vector<int>> content;
    vector<bool> visited;
    vector<int> path, colors;

public:
    Graph(int size) {
        this->size = size;
        this->content.resize(size);
        this->colors.resize(size, 0); 
        this->visited.resize(size, false);
    }

    void addEdge(int v, int u) {
        content[v - 1].push_back(u - 1);
    }

    bool detectCycle(int v) {
        colors[v] = 1; 
        for (int u : content[v]) {
            if (colors[u] == 1) 
                return true;
            if (colors[u] == 0 && detectCycle(u)) 
                return true;
        }
        colors[v] = 2; 
        return false;
    }

    void makePath(int v) {
        if (visited[v]) return;
        visited[v] = true;
        for (int u : content[v]) {
            if (!visited[u]) {
                makePath(u);
            }
        }
        path.push_back(v); 
    }

    vector<int> getTopologicalOrder() {
        return path;
    }

    bool hasVisited(int v) {
        return visited[v];
    }
};

int main() {
    int m, n; 
    cin >> m >> n;

    Graph g(m);

    for (int i = 0; i < n; i++) {
        int v, u;
        cin >> v >> u;
        g.addEdge(v, u);
    }

    bool hasCycle = false;


    for (int i = 0; i < m; i++) {
        if (!g.hasVisited(i) && g.detectCycle(i)) {
            hasCycle = true;
            break;
        }
    }

    if (hasCycle) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;

        for (int i = 0; i < m; i++) {
            if (!g.hasVisited(i)) {
                g.makePath(i);
            }
        }

        vector<int> topologicalOrder = g.getTopologicalOrder();
        for (int i = topologicalOrder.size() - 1; i >= 0; i--) {
            cout << topologicalOrder[i] + 1 << " "; 
        }
        cout << endl;
    }

    return 0;
}
