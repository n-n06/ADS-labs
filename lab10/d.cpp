#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

class Graph
{
private:
    int size;
    vector<vector<int>> content;
    map<int, int> color;
public:
    Graph(int size) {
        this->size = size;
        this->content.resize(size);
    };

    vector<vector<int>> getContent() {
        return content;
    }

    bool getColor(int v) {
        return color[v];
    }

    void addEdge(int v, int u) {
        content[v-1].push_back(u-1);
        content[u-1].push_back(v-1);
    }

    void recolor(int v) {
        color[v-1] = 1;
    }

    int redBfs(int v) {
        v--;
        queue<int> q;
        vector<bool> visit(size, false);

        q.push(v);
        visit[v] = true;

        int dist = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                if (color[node] == 1) {
                    return dist;
                }

                for (int neigh : content[node]) {
                    if (!visit[neigh]) {
                        q.push(neigh);
                        visit[neigh] = true; 
                    }
                    
                }
                
            }
            dist++;

        }

        return -1;
    }

    ~Graph() {
        content.clear();
        color.clear();
    };
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    Graph g(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        g.addEdge(v, u);
    }
    


    for (int i = 0; i < q; i++) {
        int v, type;
        cin >> type >> v;
        if (type == 1) {
            g.recolor(v);
        } else {
            cout << g.redBfs(v) << endl;
        }
    }


}


