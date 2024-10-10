#include <iostream>
#include <vector>

using namespace std;
using l_int = long long;

struct Heap {   //it is ok
    vector<l_int> heap;

    l_int parent(l_int i) { 
        return (i - 1) / 2; 
    }

    l_int left(l_int i) { 
        return (2 * i + 1); 
    }

    l_int right(l_int i) {
        return (2 * i + 2);
    }
    
    void maxHeapifyUp(l_int i) {
        l_int p = parent(i);
        if (i != 0 && heap[i] > heap[p]) {
            swap(heap[i], heap[p]);
            maxHeapifyUp(p);
        }
    }

    void maxHeapifyDown(l_int i) {
        l_int l = left(i);
        l_int r = right(i);
        l_int max = i;
        l_int size = heap.size();

        if (l < size && heap[max] < heap[l]) {
            max = l;
        }
        if (r < size && heap[max] < heap[r]) {
            max = r;
        }

        if (max != i) {
            swap(heap[i], heap[max]);
            maxHeapifyDown(max);
        }
    }
    

    l_int getSize() {
        return heap.size();
    }

    bool isEmpty() {
        return heap.empty();
    }

    void insert(l_int x) {
        heap.push_back(x);
        maxHeapifyUp(heap.size() - 1);
    }

    void popMax() {
        if (isEmpty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        maxHeapifyDown(0);
    }

    l_int getMax() {
        if (!isEmpty()) {
            return heap.front();
        }
    }
};

int main() {
    l_int n; cin >> n;
    l_int x; cin >> x;
    l_int num;

    Heap h;

    for (l_int i = 0; i < n; i++) {
        cin >> num;
        h.insert(num);
    }

    l_int price = 0;
    for (int i = 0; i < x; i++) {
        price += h.getMax();
        l_int new_ticket = h.getMax() - 1;
        h.popMax();
        h.insert(new_ticket);
    }

    cout << price;

}