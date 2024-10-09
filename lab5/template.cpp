#include <iostream>

using namespace std;

class Heap
{
private:
    int* content;
    int heap_size;
    int arr_size;
public:
    Heap(int* arr, int size) {
        content = new int[size];
        for (int i = 0; i < size; i++) {
            content[i] = arr[i];
        }
        heap_size = size;
        arr_size = size;
    };

    ~Heap() {
        delete[] content;
    };

    void print() {
        for (int i = 0; i < arr_size; i++) {
            cout << content[i] << " ";
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

    void maxHeapify(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (content[l] > content[largest] && l < heap_size) {
            largest = l;
        }
        if (content[r] > content[largest] && r < heap_size) {
            largest = r;
        }

        if (largest != i) {
            swap(content[i], content[largest]);
            maxHeapify(largest);
        }
    }

    void buildMaxHeap() {
        for (int i = (heap_size - 2) / 2; i >= 0; i--) {
            maxHeapify(i);
        }
    }

    void heapsort() {
        buildMaxHeap();
        swap(content[0], content[heap_size - 1]);
        heap_size--;
        while (heap_size > 0) {
            maxHeapify(0);
            swap(content[0], content[heap_size - 1]);
            heap_size--;
        }
    }
};