#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

/**
 * Stack Implementation using Vector
 * 
 * A stack is a linear data structure that follows the Last In First Out (LIFO) principle.
 * Operations:
 * - push(): Add element to top
 * - pop(): Remove element from top
 * - top(): Get top element without removing
 * - empty(): Check if stack is empty
 * - size(): Get number of elements
 * 
 * Time Complexity:
 * - push(): O(1)
 * - pop(): O(1)
 * - top(): O(1)
 * - empty(): O(1)
 * - size(): O(1)
 * 
 * Space Complexity: O(n) where n is the number of elements
 */

class Stack {
private:
    vector<int> data;
    
public:
    // Constructor
    Stack() {}
    
    // Push element to the top of the stack
    void push(int value) {
        data.push_back(value);
    }
    
    // Remove and return the top element
    int pop() {
        if (empty()) {
            throw runtime_error("Stack is empty! Cannot pop from empty stack.");
        }
        int topElement = data.back();
        data.pop_back();
        return topElement;
    }
    
    // Get the top element without removing it
    int top() {
        if (empty()) {
            throw runtime_error("Stack is empty! Cannot get top of empty stack.");
        }
        return data.back();
    }
    
    // Check if stack is empty
    bool empty() {
        return data.empty();
    }
    
    // Get the size of the stack
    int size() {
        return data.size();
    }
    
    // Display the stack
    void display() {
        if (empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        
        cout << "Stack (top to bottom): ";
        for (int i = data.size() - 1; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

// Demo function to show stack operations
void demonstrateStack() {
    cout << "=== Stack Implementation Demo ===" << endl;
    
    Stack s;
    
    // Push elements
    cout << "Pushing elements: 10, 20, 30, 40, 50" << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    
    // Display stack
    s.display();
    cout << "Stack size: " << s.size() << endl;
    cout << "Top element: " << s.top() << endl;
    
    // Pop elements
    cout << "\nPopping elements:" << endl;
    while (!s.empty()) {
        cout << "Popped: " << s.pop() << endl;
        s.display();
    }
    
    // Try to pop from empty stack
    cout << "\nTrying to pop from empty stack:" << endl;
    try {
        s.pop();
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

int main() {
    demonstrateStack();
    return 0;
}
