/*
1. implement a min heap - use structs or classes idk
2. insert all of the elements
3. call function to pop the min element 2 times and then insert their sum and min_heapify again
4. repeat this process until the heap size is 1
5. return the sum (store it in a class var?)


*/
#include <iostream>

using namespace std;

class Heap
{
private:
    long long int* content;
    long long int heap_size;
    long long int arr_size;
public:
    Heap(long long int* arr, long long int size) {
        content = new long long int[size];
        for (long long int i = 0; i < size; i++) {
            content[i] = arr[i];
        }
        heap_size = size;
        arr_size = size;
    };

    ~Heap() {
        delete[] content;
    };

    void print() {
        for (long long int i = 0; i < heap_size; i++) {
            cout << content[i] << " ";
        }
        cout << endl;
    }

    long long int parent(long long int i) {
        return (i - 1) / 2; 
    }

    long long int left(long long int i) {
        return (i * 2 + 1);
    }

    long long int right(long long int i) {
        return (i * 2 + 2);
    }

    void minHeapify(long long int i) {
        long long int smallest = i;
        long long int l = left(i);
        long long int r = right(i);

        if (content[l] < content[smallest] && l < heap_size) {
            smallest = l;
        }
        if (content[r] < content[smallest] && r < heap_size) {
            smallest = r;
        }

        if (smallest != i) {
            swap(content[i], content[smallest]);
            minHeapify(smallest);
        }
    }

    void buildMinHeap() {
        for (long long int i = (heap_size - 2) / 2; i >= 0; i--) {
            minHeapify(i);
        }
    }

    long long int popMin() {
        swap(content[0], content[heap_size - 1]);
        heap_size--;
        minHeapify(0);
        return content[heap_size];
    }

    void insert(long long int value) {
        content[heap_size] = value;
        heap_size++;
        minHeapify(0);
    }

    bool isFinished() {
        return heap_size == 1;
    }

};

int main() {
    long long int n; cin >> n;
    long long int arr[n];

    for (long long int i = 0; i < n; i++) {
        cin >> arr[i];
    } 

    Heap h(arr, n);
    h.buildMinHeap();

    long long int sum = 0;

    while (!h.isFinished()) {
        long long int min1 = h.popMin();
        long long int min2 = h.popMin();
        sum += (min1 + min2); 
        h.insert(min1 + min2);
    }

    cout << sum;
    
}