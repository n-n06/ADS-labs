#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph
{
private:
    vector<pair<int/*edge weight*/, pair<int, int>/*indices of vertices*/>> edges;
    int edge_size;
    int vertex_size;
    vector<int> parents;

public:
    Graph(int vertex_size) {
        edge_size = 0;
        this->vertex_size = vertex_size;
        parents.resize(vertex_size);

        for (int i = 0; i < vertex_size; i++) {
            parents[i] = i;
        }

    };

    void addEdge(int w, int v1, int v2) {
        edges.push_back({w, {v1, v2}});
        edge_size++;
    }

    void print() {
        for (int i = 0; i < edge_size; i++)
        {
            int w = edges[i].first;
            int v1 = edges[i].second.first;
            int v2 = edges[i].second.second;

            cout << v1 << "<==>" << v2 << " = " << w << endl;
        }
        
    }


    int oldest_predecessor(int v) {
        int p = parents[v];

        while (parents[p] != p) {
            p = parents[p];
        }

        return p;
    }


    void change_parents(int v1, int v2) {
        int old = oldest_predecessor(v2);
        parents[old] = v1;
    }
    


    int kruskal() {
        sort(edges.begin(), 
            edges.end(), 
            [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) 
                {
                    return a.first < b.first;
                }
            );

        int min_cost = 0;
        int cost = 0;

        for (int i = 0; i < edge_size; i++) {
            int w = edges[i].first;
            int v1 = edges[i].second.first;
            int v2 = edges[i].second.second;


            if (oldest_predecessor(v1) != oldest_predecessor(v2)) {
                change_parents(v1, v2);
                min_cost += (w);
            }
        }



        return min_cost;
    }
};

int main() {
    int n; cin >> n;
    int num, v1, v2, w;

    Graph g(n);

    for (int i = 0; i < n; i++) {
        for (int k = n - i; k < n; k++) {
            cin >> num;
        }
        for (int j = i; j < n; j++) {
            cin >> w;
            g.addEdge(w, i, j);
        }
    }

    cout << g.kruskal();

}   