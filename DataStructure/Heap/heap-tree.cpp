#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

/**
 * Min Heap Implementation using Vector
 *
 * A Min Heap is a complete binary tree where each node <= its children.
 * Operations:
 *  - insert(): O(log n)
 *  - pop():    O(log n)  (remove and return min)
 *  - top():    O(1)
 *  - empty():  O(1)
 *  - size():   O(1)
 *
 * Space: O(n)
 */
class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        if (index == 0) return;
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < n && heap[left] < heap[smallest]) smallest = left;
        if (right < n && heap[right] < heap[smallest]) smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap() {}

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int pop() {
        if (empty()) throw runtime_error("MinHeap is empty! Cannot pop.");
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!empty()) heapifyDown(0);
        return minVal;
    }

    int top() {
        if (empty()) throw runtime_error("MinHeap is empty! Cannot get top.");
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }

    int size() {
        return static_cast<int>(heap.size());
    }

    // Display underlying array (level-order)
    void display() {
        if (empty()) {
            cout << "MinHeap is empty" << endl;
            return;
        }
        cout << "MinHeap (array order): ";
        for (int v : heap) cout << v << " ";
        cout << endl;
    }
};

/**
 * Max Heap Implementation using Vector
 *
 * A Max Heap is a complete binary tree where each node >= its children.
 * Same operations as MinHeap, but comparisons reversed.
 */
class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        if (index == 0) return;
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < n && heap[left] > heap[largest]) largest = left;
        if (right < n && heap[right] > heap[largest]) largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap() {}

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int pop() {
        if (empty()) throw runtime_error("MaxHeap is empty! Cannot pop.");
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!empty()) heapifyDown(0);
        return maxVal;
    }

    int top() {
        if (empty()) throw runtime_error("MaxHeap is empty! Cannot get top.");
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }

    int size() {
        return static_cast<int>(heap.size());
    }

    void display() {
        if (empty()) {
            cout << "MaxHeap is empty" << endl;
            return;
        }
        cout << "MaxHeap (array order): ";
        for (int v : heap) cout << v << " ";
        cout << endl;
    }
};

// Demo function to show both heaps
void demonstrateHeaps() {
    cout << "=== MinHeap Demo ===" << endl;
    MinHeap minH;
    cout << "Inserting: 20, 15, 30, 5, 10" << endl;
    minH.insert(20);
    minH.insert(15);
    minH.insert(30);
    minH.insert(5);
    minH.insert(10);
    minH.display();
    cout << "MinHeap size: " << minH.size() << endl;
    cout << "Min element: " << minH.top() << endl;
    cout << "Popping all elements (min first):" << endl;
    while (!minH.empty()) {
        cout << "Popped: " << minH.pop() << endl;
        minH.display();
    }

    cout << "\n=== MaxHeap Demo ===" << endl;
    MaxHeap maxH;
    cout << "Inserting: 20, 15, 30, 5, 10" << endl;
    maxH.insert(20);
    maxH.insert(15);
    maxH.insert(30);
    maxH.insert(5);
    maxH.insert(10);
    maxH.display();
    cout << "MaxHeap size: " << maxH.size() << endl;
    cout << "Max element: " << maxH.top() << endl;
    cout << "Popping all elements (max first):" << endl;
    while (!maxH.empty()) {
        cout << "Popped: " << maxH.pop() << endl;
        maxH.display();
    }

    // Demonstrate exception handling
    cout << "\nAttempting to pop from empty MinHeap (should show error):" << endl;
    try {
        minH.pop();
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

int main() {
    demonstrateHeaps();
    return 0;
}
