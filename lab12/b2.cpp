#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Heap
{
private:
    vector<pair<int, int>> content;
    int heap_size;
    int arr_size;
public:
    Heap(vector<int> arr, int size) {
        content.resize(size);
        for (int i = 0; i < size; i++) {
            content[i] = {i, arr[i]};
        }
        heap_size = size;
        arr_size = size;
    };

    bool isEmpty() {
        return heap_size == 0;
    }

    void print() {
        for (int i = 0; i < arr_size; i++) {
            cout << content[i].first << " " << content[i].second << endl;
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

        if (content[l].second < content[smallest].second && l < heap_size) {
            smallest = l;
        }
        if (content[r].second < content[smallest].second && r < heap_size) {
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



    pair<int,int> pop() {
        pair<int,int> min = content[0];
        swap(content[0], content[heap_size - 1]);
        heap_size--;
        minHeapify(0);
        return min;
    }
    
    void decreaseKey(int v, int new_key) {
        int index;
        for (int i = 0; i < heap_size; i++) {
            if (v == content[i].first) {
                index = i;
                break;
            }
        }

        if (new_key < content[index].second) {
            content[index].second = new_key;
        }


        while (index > 0 && content[parent(index)].second > content[index].second) {
            swap(content[index], content[parent(index)]);
            index = parent(index);
        }
    }
};

int v_size, e_size;
vector<int> dist;
vector<int> parent;
int v1, v2, w;
vector<vector<pair<int, int>>> adj;

int dijkstra(int start, int end) {

    for (int i = 0; i < v_size; i++) {
        dist[i] = INT32_MAX;
        parent[i] = -1;
    }

    dist[start] = 0;
    bool visited[v_size];

    for (int i = 0; i < v_size; i++) {
        visited[i] = false;
    }

    Heap pq(dist, v_size);
    pq.buildMinHeap();

    while (!pq.isEmpty()) {
        pair<int, int> u = pq.pop();
        visited[u.first] = true;
        // cout << u.first << " ";
        for (pair<int, int> edge : adj[u.first]) {
            int v = edge.first;
            int w = edge.second;
            if (!visited[v]) {
                if (dist[v] > dist[u.first] + w) {
                    dist[v] = dist[u.first] + w;
                    parent[v] = u.first;
                    pq.decreaseKey(v, dist[v]);
                }
            }

        }
    }
    return dist[end];

}

int main() {
    cin >> v_size >> e_size;
    // vector<pair<int, pair<int, int>>> edges;
    dist.resize(v_size);
    parent.resize(v_size);
    adj.resize(v_size);

    for (int i = 0; i < e_size; i++) {
        cin >> v1 >> v2 >> w;
        v1--; v2--;
        adj[v1].push_back({v2,w});
        adj[v2].push_back({v1,w});
    }

    int s, a, b, f;
    cin >> s >> a >> b >> f;
    s--; a--; b--; f--;

    int dist = min(dijkstra(s,a) + dijkstra(a,b) + dijkstra(b,f),
                    dijkstra(s,b) + dijkstra(b, a) + dijkstra(a, f));
    if (dist < 0) {
        cout << -1;
    } else {
        cout << dist;
    }
}