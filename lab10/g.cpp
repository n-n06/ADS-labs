#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

class EVA01
{
private:
    int size;
    vector<vector<int>> content;
public:
    EVA01(int size) {
        this->size = size;
        this->content.resize(size);
    };

    vector<vector<int>> getContent() {
        return content;
    }


    void addEdge(int v, int u) {
        content[v-1].push_back(u-1);
    }

    int thirdImpactDFS() {
        int adam = 0;
        vector<bool> visit(size, false);
        stack <int> st;

        st.push(adam);
        visit[adam] = true;

        int rei = 0;

        while (!st.empty()) {
            int angel = st.top(); st.pop();

            for (int subangel : content[angel]) {
                if (!visit[subangel]) {
                    st.push(subangel);
                    visit[subangel] = true;
                } else {
                    rei++;
                }
            }
        }

        return rei;

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

    ~EVA01() {
        content.clear();
    };
};

int main() {
    int V, E;
    cin >> V >> E;

    EVA01 g(V);

    for (int i = 0; i < E; i++) {
        int v,u;
        cin >> v >> u;
        g.addEdge(v, u);
    }


    if (g.thirdImpactDFS() <= 1) {
        cout << "YES";
    } else {
        cout <<"NO";
    }


}