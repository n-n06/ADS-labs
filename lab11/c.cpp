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
    vector<string> types;
    int price_big;
    int price_small;

public:
    Graph(int vertex_size, int x, int y) {
        edge_size = 0;
        this->vertex_size = vertex_size;
        parents.resize(vertex_size);
        types.resize(vertex_size);

        for (int i = 0; i < vertex_size; i++) {
            parents[i] = i;
        }

        price_big = x;
        price_small = y;
    };

    void addEdge(int w, int v1, int v2, string type) {
        if (type == "big") {
            w *=  price_big;
        } else if (type == "small") {
            w *= price_small;
        } else {
            w *= min(price_big, price_small);
        }
        edges.push_back({w, {v1, v2}});
        edge_size++;
        types[v1] = type;
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
    int v, e;
    cin >> v >> e;
    int x, y;
    cin >> x >> y;

    Graph g(v, x, y);

    for (int i = 0; i < e; i++) {
        string type;
        int v1, v2, w;
        cin >> type >> v1 >> v2 >> w;
        g.addEdge(w, v1, v2, type);
    }
    

    cout << g.kruskal();
}   