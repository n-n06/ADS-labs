#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

class SkibidiGraph
{
private:
    int size;
    vector<vector<int>> content;
public:
    SkibidiGraph(int size) {
        this->size = size;
        this->content.resize(size);
    };

    vector<vector<int>> getContent() {
        return content;
    }


    void addEdge(int v, int u) {
        content[v-1].push_back(u-1);
        content[u-1].push_back(v-1);
    }



    bool bfs(int v, int u) {
        v--;
        u--;
        queue<int> q;
        vector<bool> visit(size, false);

        q.push(v);
        visit[v] = true;


        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == u) {
                return true;
            }

            for (int neigh : content[node]) {


                if (!visit[neigh]) {
                    q.push(neigh);
                    visit[neigh] = true; 
                }
                
            }
        }

        return false;
    }

    ~SkibidiGraph() {
        content.clear();
    };
};

int main() {
    int V, E;
    cin >> V >> E;

    SkibidiGraph g(V);

    for (int i = 0; i < E; i++) {
        int v,u;
        cin >> v >> u;
        g.addEdge(v, u);
    }

    int s, t;
    cin >> s >> t;
    if (g.bfs(s, t)) {
        cout << "YES";
    } else {
        cout <<"NO";
    }


}