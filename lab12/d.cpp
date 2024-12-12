#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;
using ll = long long;

class Heap
{
private:
    vector<pair<int, long long int>> content;
    int heap_size;
    int arr_size;
public:
    Heap(vector<pair<int, long long int>> arr, int size) {
        content.resize(size);
        for (int i = 0; i < size; i++) {
            content[i] = arr[i];
        }
        heap_size = size;
        arr_size = size;
        buildMinHeap();
    };

    bool isEmpty() {
        return heap_size == 0;
    }

    void print() {
        for (int i = 0; i < arr_size; i++) {
            cout << content[i].first << ":(" << content[i].second << ")";
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

    pair<int, long long int> pop() {
        pair<int, long long int> min = content[0];
        swap(content[0], content[heap_size - 1]);
        heap_size--;
        minHeapify(0);
        return min;
    }
    
    void decreaseKey(int v, long long int new_key) {
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


class Graph
{
private:

    vector<pair<ll, ll>> vert;
    vector<ll> dist;
    vector<bool> visited;
public:
    Graph(int v) {
        dist.resize(v);
        vert.resize(v);
        visited.resize(v);

        for (int i = 0; i < v; i++) {
            visited[i] = false;
            dist[i] = (ll) INT32_MAX;
        }
    };

    void addEdge(ll v1, ll val1, ll val2) {
        vert[v1].first = val1;
        vert[v1].second = val2;
    }

    int dijkstra(int start, int end) {
        dist[start] = 0;
        for(ll i = 0; i < vert.size(); i++){
            ll v = -1;
            for(ll j = 0; j < vert.size(); j++) {
                if (!visited[j] && (v == -1 || dist[j] < dist[v])) {
                    v = j;
                }
            }

            if (v == -1 || dist[v] == (ll) INT32_MAX) {
                break;
            }

            visited[v] = true;
            for(ll j = 0; j < vert.size(); j++){
                ll dest = j;
                ll len = abs(vert[j].first - vert[v].first)  + abs(vert[j].second - vert[v].second);
                dist[dest] = min(dist[dest], max(dist[v], len));
            }
        }
        return dist[end];
    }
};



int main() {
    int n; 
    cin >> n;

    Graph g(n);

    for(long long i = 0; i < n; i++){
        ll val1, val2; cin >> val1 >> val2;
        g.addEdge(i, val1, val2);
    }
    cout << g.dijkstra(0, n-1);
    return 0;

}




