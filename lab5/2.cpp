/*
max heap
 */
#include <iostream>

using namespace std;

class Heap
{
private:
    long long int* content;
    int heap_size;
    int arr_size;
public:
    Heap(long long int* arr, int size) {
        content = new long long int[size];
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
        for (int i = 0; i < heap_size; i++) {
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

    long long int popMax() {
        swap(content[0], content[heap_size - 1]);
        heap_size--;
        maxHeapify(0);
        return content[heap_size];
    }

    void insert(long long int value) {
        content[heap_size] = value;
        heap_size++;
        buildMaxHeap();
    }

    void smashRocks() {
        long long int max1 = popMax();
        long long int max2 = popMax();

        if (max1 > max2) {
            insert(max1 - max2);
        }
    }

    bool isFinished() {
        return heap_size <= 1;
    }

    int print_size() {
        return heap_size;
    }

    long long int printResult() {
        if (heap_size == 0) {
            return 0;
        } else {
            return content[0];
        }
    }
};

int main() {
    int n; cin >> n;

    long long int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Heap h(arr, n);
    h.buildMaxHeap();

    while (!h.isFinished()) {
        h.smashRocks();
    }
    cout << h.printResult();

}