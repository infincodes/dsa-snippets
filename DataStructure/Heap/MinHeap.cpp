#include <iostream>
#include <vector>
#include <stdexcept>

class MinHeap {
private:
    std::vector<int> heap;
    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }
    
    void heapify(int index) {
        int smallest = index;
        int left = leftChild(index);
        int right = rightChild(index);
        
        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
            
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;
            
        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapify(smallest);
        }
    }
    
public:
    MinHeap() {}
    

    void insert(int value) {
        heap.push_back(value);
        
        int current = heap.size() - 1;
        while (current > 0 && heap[current] < heap[parent(current)]) {
            std::swap(heap[current], heap[parent(current)]);
            current = parent(current);
        }
    }
    

    int extractMin() {
        if (heap.empty())
            throw std::runtime_error("Heap is empty");
            
        int min = heap[0];

        heap[0] = heap.back();
        heap.pop_back();
        
        if (!heap.empty())
            heapify(0);
            
        return min;
    }
    

    int getMin() const {
        if (heap.empty())
            throw std::runtime_error("Heap is empty");
        return heap[0];
    }
    

    bool isEmpty() const {
        return heap.empty();
    }
    

    size_t size() const {
        return heap.size();
    }
};

int main() {
    MinHeap minHeap;
    
    // Insert some elements
    minHeap.insert(3);
    minHeap.insert(2);
    minHeap.insert(1);
    minHeap.insert(15);
    minHeap.insert(5);
    minHeap.insert(4);
    
    std::cout << "Size of heap: " << minHeap.size() << std::endl;
    
    // Extract elements in order (should come out sorted)
    std::cout << "Extracting elements from heap:" << std::endl;
    while (!minHeap.isEmpty()) {
        std::cout << minHeap.extractMin() << " ";
    }
    std::cout << std::endl;
    
    return 0;
}