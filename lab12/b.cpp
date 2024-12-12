#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdint>

using namespace std;




class Heap
{
private:
    vector<pair<int/*index*/, pair<int/*distance*/,int/*predecessor's index*/>>> content;
    int heap_size;
    int arr_size;
public:
    Heap(vector<pair<int/*index*/, pair<int/*distance*/,int/*predecessor's index*/>>> arr, int size) {
        content.resize(size);
        for (int i = 0; i < size; i++) {
            content[i] = arr[i];
        }
        heap_size = size;
        arr_size = size;
    };

    bool isEmpty() {
        return heap_size == 0;
    }

    void print() {
        for (int i = 0; i < arr_size; i++) {
            cout << content[i].first << ":(" << content[i].second.first << ";" << content[i].second.second<< ")";
        }
        cout << endl;
    }

    int parent(int i) {
        return (i - 1) / 2; 
    }

    int left(int i) {
        return (i * 2 + 1);
    }

    int right(int i) {
        return (i * 2 + 2);
    }

    void minHeapify(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (content[l].second.first < content[smallest].second.first && l < heap_size) {
            smallest = l;
        }
        if (content[r].second.first < content[smallest].second.first && r < heap_size) {
            smallest = r;
        }

        if (smallest != i) {
            swap(content[i], content[smallest]);
            minHeapify(smallest);
        }
    }

    void buildMinHeap() {
        for (int i = (heap_size - 2) / 2; i >= 0; i--) {
            minHeapify(i);
        }
    }

    // void heapsort() {
    //     buildMaxHeap();
    //     swap(content[0], content[heap_size - 1]);
    //     heap_size--;
    //     while (heap_size > 0) {
    //         maxHeapify(0);
    //         swap(content[0], content[heap_size - 1]);
    //         heap_size--;
    //     }
    // }

    pair<int, pair<int, int>> pop() {
        pair<int, pair<int,int>> min = content[0];
        swap(content[0], content[heap_size - 1]);
        heap_size--;
        minHeapify(0);
        return min;
    }
    
    void decreaseKey(int v, int new_key, int pred) {
        int index;
        for (int i = 0; i < heap_size; i++) {
            if (v == content[i].first) {
                index = i;
                break;
            }
        }

        if (new_key < content[index].second.first) {
            content[index].second.first = new_key;  
            content[index].second.second = pred;
        }


        while (index > 0 && content[parent(index)].second.first > content[index].second.first) {
            swap(content[index], content[parent(index)]);
            index = parent(index);
        }
    }
};



class Graph
{
private:
    vector<vector<pair<int/*neightbor*/,int/*weight*/>>> adj;
    vector<pair<int/*index*/, pair<int/*distance*/,int/*predecessor's index*/>>> vert;
    vector<bool> visited;
public:
    Graph(int size) {
        vert.resize(size);
        adj.resize(size);
        visited.resize(size);

        for (int i = 0; i < size; i++) {
            vert[i].first = i;
            vert[i].second.first = 1e7;
            vert[i].second.second = -1;
            visited[i] = false;
        }
    };

    void addEdge(int v1, int v2, int w) {
        adj[v1].push_back({v2,w});
        adj[v2].push_back({v1, w});
    }

    // int dijkstra(int start) {
    //     for (int i = 0; i < adj.size(); i++) {

    //     }
    //     Heap minHeap();
    // }

    void clean_up() {
        for (int i = 0; i < visited.size(); i++) {
            visited[i] = false;
        }
    }

    void show() {
        for (pair<int, int> el : adj[0]) {
            cout << el.first << " " << el.second << endl;
        }
    }

    int dijkstra(int root, int dest) {
        Heap minHeap(vert, vert.size());

        minHeap.decreaseKey(root, 0, root);
        minHeap.buildMinHeap();
        pair<int, pair<int, int>> v;

        while(!minHeap.isEmpty()) {
            v = minHeap.pop();
            visited[v.first] = true;
            // cout << v.first << " ";
            // minHeap.print();

            int init_cost = v.second.first;
            for (pair<int, int> n : adj[v.first]) {
                if (!visited[n.first]) {
                    minHeap.decreaseKey(n.first, n.second + init_cost, v.first);
                }
            }

            if (v.first == dest) {
                clean_up();
                return v.second.first;
            }
        }


        clean_up();
        return -1;
    }
    
};

int main() {
    int v; cin >> v;
    int e; cin >> e;
    Graph g(v);
    for (int i = 0; i < e; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        v1--; v2--;
        g.addEdge(v1, v2, w);
    }

    int s, a, b, f;
    cin >> s >> a >> b >> f;
    s--; a--; b--; f--;

    vector <int> dist;
    dist.push_back(g.dijkstra(s, a));
    dist.push_back(g.dijkstra(a, b));
    dist.push_back(g.dijkstra(b, f));
    
    g.show();

    for (int d : dist) {
        cout << d;
        if (d == -1 || d >= 1e7) {
            cout << -1;
            return 0;
        }
    }
    cout << min(g.dijkstra(s, a) + g.dijkstra(a, b) + g.dijkstra(b ,f), 
                g.dijkstra(s, b) + g.dijkstra(b, a) + g.dijkstra(a ,f));
}


