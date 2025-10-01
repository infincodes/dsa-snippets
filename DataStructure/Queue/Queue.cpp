#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

/**
 * Queue Implementation using Vector
 * 
 * A queue is a linear data structure that follows the First In First Out (FIFO) principle.
 * Operations:
 * - enqueue(): Add element to rear
 * - dequeue(): Remove element from front
 * - front(): Get front element without removing
 * - empty(): Check if queue is empty
 * - size(): Get number of elements
 * 
 * Time Complexity:
 * - enqueue(): O(1)
 * - dequeue(): O(n) - due to vector shifting
 * - front(): O(1)
 * - empty(): O(1)
 * - size(): O(1)
 * 
 * Space Complexity: O(n) where n is the number of elements
 * 
 * Note: For better performance, consider using a circular array or linked list
 */

class Queue {
private:
    vector<int> data;
    
public:
    // Constructor
    Queue() {}
    
    // Add element to the rear of the queue
    void enqueue(int value) {
        data.push_back(value);
    }
    
    // Remove and return the front element
    int dequeue() {
        if (empty()) {
            throw runtime_error("Queue is empty! Cannot dequeue from empty queue.");
        }
        int frontElement = data.front();
        data.erase(data.begin());
        return frontElement;
    }
    
    // Get the front element without removing it
    int front() {
        if (empty()) {
            throw runtime_error("Queue is empty! Cannot get front of empty queue.");
        }
        return data.front();
    }
    
    // Get the rear element without removing it
    int rear() {
        if (empty()) {
            throw runtime_error("Queue is empty! Cannot get rear of empty queue.");
        }
        return data.back();
    }
    
    // Check if queue is empty
    bool empty() {
        return data.empty();
    }
    
    // Get the size of the queue
    int size() {
        return data.size();
    }
    
    // Display the queue
    void display() {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Queue (front to rear): ";
        for (int i = 0; i < data.size(); i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

// Demo function to show queue operations
void demonstrateQueue() {
    cout << "=== Queue Implementation Demo ===" << endl;
    
    Queue q;
    
    // Enqueue elements
    cout << "Enqueuing elements: 10, 20, 30, 40, 50" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    // Display queue
    q.display();
    cout << "Queue size: " << q.size() << endl;
    cout << "Front element: " << q.front() << endl;
    cout << "Rear element: " << q.rear() << endl;
    
    // Dequeue elements
    cout << "\nDequeuing elements:" << endl;
    while (!q.empty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
        q.display();
    }
    
    // Try to dequeue from empty queue
    cout << "\nTrying to dequeue from empty queue:" << endl;
    try {
        q.dequeue();
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

int main() {
    demonstrateQueue();
    return 0;
}
