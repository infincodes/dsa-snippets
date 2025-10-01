import java.util.ArrayList;
import java.util.NoSuchElementException;

/**
 * Queue Implementation using ArrayList
 * 
 * A queue is a linear data structure that follows the First In First Out (FIFO) principle.
 * Operations:
 * - enqueue(): Add element to rear
 * - dequeue(): Remove element from front
 * - front(): Get front element without removing
 * - rear(): Get rear element without removing
 * - isEmpty(): Check if queue is empty
 * - size(): Get number of elements
 * 
 * Time Complexity:
 * - enqueue(): O(1)
 * - dequeue(): O(n) - due to ArrayList shifting
 * - front(): O(1)
 * - rear(): O(1)
 * - isEmpty(): O(1)
 * - size(): O(1)
 * 
 * Space Complexity: O(n) where n is the number of elements
 * 
 * Note: For better performance, consider using a circular array or linked list
 */

public class Queue {
    private ArrayList<Integer> data;
    
    // Constructor
    public Queue() {
        data = new ArrayList<>();
    }
    
    // Add element to the rear of the queue
    public void enqueue(int value) {
        data.add(value);
    }
    
    // Remove and return the front element
    public int dequeue() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty! Cannot dequeue from empty queue.");
        }
        return data.remove(0);
    }
    
    // Get the front element without removing it
    public int front() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty! Cannot get front of empty queue.");
        }
        return data.get(0);
    }
    
    // Get the rear element without removing it
    public int rear() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty! Cannot get rear of empty queue.");
        }
        return data.get(data.size() - 1);
    }
    
    // Check if queue is empty
    public boolean isEmpty() {
        return data.isEmpty();
    }
    
    // Get the size of the queue
    public int size() {
        return data.size();
    }
    
    // Display the queue
    public void display() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return;
        }
        
        System.out.print("Queue (front to rear): ");
        for (int i = 0; i < data.size(); i++) {
            System.out.print(data.get(i) + " ");
        }
        System.out.println();
    }
    
    // Demo function to show queue operations
    public static void demonstrateQueue() {
        System.out.println("=== Queue Implementation Demo ===");
        
        Queue q = new Queue();
        
        // Enqueue elements
        System.out.println("Enqueuing elements: 10, 20, 30, 40, 50");
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);
        
        // Display queue
        q.display();
        System.out.println("Queue size: " + q.size());
        System.out.println("Front element: " + q.front());
        System.out.println("Rear element: " + q.rear());
        
        // Dequeue elements
        System.out.println("\nDequeuing elements:");
        while (!q.isEmpty()) {
            System.out.println("Dequeued: " + q.dequeue());
            q.display();
        }
        
        // Try to dequeue from empty queue
        System.out.println("\nTrying to dequeue from empty queue:");
        try {
            q.dequeue();
        } catch (NoSuchElementException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
    
    public static void main(String[] args) {
        demonstrateQueue();
    }
}
