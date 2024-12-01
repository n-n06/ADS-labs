#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Graph {
private:
    vector<pair<long long, pair<long long, long long>>> edges;
    vector<long long> parents;

public:
    vector<long long> left, right;

    Graph(int vertex_count) {
        parents.resize(vertex_count);
        left.resize(vertex_count);
        right.resize(vertex_count);

        for (long long i = 0; i < vertex_count; i++) {
            parents[i] = i;
            left[i] = right[i] = i;
        }
    }

    void addEdge(long long weight, long long u, long long v) {
        edges.push_back({weight, {u, v}});
    }

    void sortEdges() {
        sort(edges.begin(), edges.end());
    }

    long long find(long long v) {
        if (parents[v] == v) return v;
        return parents[v] = find(parents[v]);
    }

    bool merge(long long u, long long v) {
        u = find(u);
        v = find(v);

        if (u == v) return false;

        if (rand() % 2) swap(u, v);

        parents[u] = v;
        left[v] = min(left[u], left[v]);
        right[v] = max(right[u], right[v]);

        return true;
    }

    vector<pair<long long, pair<long long, long long>>> getEdges() {
        return edges;
    }


};

int main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();

    long long int n, m, a, b, c;
    cin >> n >> m;

    Graph g(n);

    vector<pair<long long int, pair<long long int, long long int>>> edges;

    for (int i = 0; i < m; i++){
        cin >> a >> b >> c; 
        a--, b--;
        g.addEdge(c, a, b);
    }
    g.sortEdges();

    edges = g.getEdges();
    vector<long long int> left;
    vector<long long int> right;

    long long int ans = 0, mm = -1, coutnt = 0;

    for(auto i : edges){
        if ( coutnt >= n-1) {
            break;
        }
        long long int l, r, c;
        l = i.second.first;
        r = i.second.second;
        c = i.first;
        mm = l;

        for(long long int i = l; i <= r; i++) {
            if (g.find(i) != i) {
                mm = g.find(i);
                break;
            }
        }
        if (g.left[mm] <= l && r <= g.right[mm]) continue;
        else if (g.left[mm] <= r && r <=g.right[mm]) r = g.left[mm];
        else if (g.left[mm] <= l && l <= g.right[mm]) l = g.right[mm];
        for(long long int i = l; i <= r; i++){
            if (g.merge(mm, i)) {
                ans += c, coutnt++;
            }
        }
    }
    cout << ans;


    return 0;
}