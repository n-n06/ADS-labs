/*
max heap
 */
#include <iostream>
#include <vector>

using namespace std;
using l_int = long long;

struct Heap {   //i do not like this code 
    vector<l_int> heap;

    l_int parent(l_int i) { 
        return (i - 1) / 2; 
    }

    l_int left(l_int i) { 
        return (2*i + 1); 
    }

    l_int right(l_int i) {
        return (2*i + 2);
    }
    
    void minHeapifyUp(l_int i) {
        l_int p = parent(i);
        if (i != 0 && heap[i] < heap[p]) {
            swap(heap[i], heap[p]);
            minHeapifyUp(p);
        }
    }

    void minHeapifyDown(l_int i) {
        l_int l = left(i);
        l_int r = right(i);
        l_int min = i;
        l_int size = heap.size();

        if (l < size && heap[min] > heap[l]) {
            min = l;
        }
        if (r < size && heap[min] > heap[r]) {
            min = r;
        }

        if (min != i) {
            swap(heap[i], heap[min]);
            minHeapifyDown(min);
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
        minHeapifyUp(heap.size() - 1);
    }

    void popMin() {
        if (isEmpty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        minHeapifyDown(0);
    }

    l_int getMin() {
        if (!isEmpty()) {
            return heap.front();
        }
    }
};



int main() {
    l_int q; cin >> q;
    l_int k; cin >> k;

    l_int arr[k] = {};

    string input;

    Heap h;
    l_int sum = 0;

    for (int i = 0; i < q; i++) {
        cin >> input;
        if (input == "print") {
            cout << sum << endl;
        } else if (input == "insert") {
            l_int num; cin >> num;
            if (h.getSize() < k) {
                h.insert(num);
                sum += num;
            }
            else if (h.getMin() < num) {
                sum += (num - h.getMin());
                h.popMin();
                h.insert(num);
            }
        }
    }

}