import java.util.ArrayList;
import java.util.EmptyStackException;

/**
 * Stack Implementation using ArrayList
 * 
 * A stack is a linear data structure that follows the Last In First Out (LIFO) principle.
 * Operations:
 * - push(): Add element to top
 * - pop(): Remove element from top
 * - peek(): Get top element without removing
 * - isEmpty(): Check if stack is empty
 * - size(): Get number of elements
 * 
 * Time Complexity:
 * - push(): O(1)
 * - pop(): O(1)
 * - peek(): O(1)
 * - isEmpty(): O(1)
 * - size(): O(1)
 * 
 * Space Complexity: O(n) where n is the number of elements
 */

public class Stack {
    private ArrayList<Integer> data;
    
    // Constructor
    public Stack() {
        data = new ArrayList<>();
    }
    
    // Push element to the top of the stack
    public void push(int value) {
        data.add(value);
    }
    
    // Remove and return the top element
    public int pop() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return data.remove(data.size() - 1);
    }
    
    // Get the top element without removing it
    public int peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return data.get(data.size() - 1);
    }
    
    // Check if stack is empty
    public boolean isEmpty() {
        return data.isEmpty();
    }
    
    // Get the size of the stack
    public int size() {
        return data.size();
    }
    
    // Display the stack
    public void display() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return;
        }
        
        System.out.print("Stack (top to bottom): ");
        for (int i = data.size() - 1; i >= 0; i--) {
            System.out.print(data.get(i) + " ");
        }
        System.out.println();
    }
    
    // Demo function to show stack operations
    public static void demonstrateStack() {
        System.out.println("=== Stack Implementation Demo ===");
        
        Stack s = new Stack();
        
        // Push elements
        System.out.println("Pushing elements: 10, 20, 30, 40, 50");
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        
        // Display stack
        s.display();
        System.out.println("Stack size: " + s.size());
        System.out.println("Top element: " + s.peek());
        
        // Pop elements
        System.out.println("\nPopping elements:");
        while (!s.isEmpty()) {
            System.out.println("Popped: " + s.pop());
            s.display();
        }
        
        // Try to pop from empty stack
        System.out.println("\nTrying to pop from empty stack:");
        try {
            s.pop();
        } catch (EmptyStackException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
    
    public static void main(String[] args) {
        demonstrateStack();
    }
}
