#include <iostream>
#define MAX_SIZE 100 // Defines the maximum size of the queue

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    // Constructor to initialize the queue
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Function to add an element to the rear of the queue (enqueue)
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue Overflow! Cannot enqueue " << value << std::endl;
            return;
        }
        if (front == -1) { // If it's the first element
            front = 0;
        }
        rear++;
        arr[rear] = value;
        std::cout << value << " enqueued to queue." << std::endl;
    }

    // Function to remove an element from the front of the queue (dequeue)
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow! Cannot dequeue." << std::endl;
            return -1; // Return -1 to indicate an error or empty queue
        }
        int value = arr[front];
        front++;
        return value;
    }

    // Function to get the front element of the queue without removing it
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1; // Return -1 to indicate an error or empty queue
        }
        return arr[front];
    }

    // Function to display all the elements in the queue
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        std::cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

// Main function to demonstrate queue operations
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display(); // Display the queue

    std::cout << "Front element is: " << q.peek() << std::endl;

    int dequeued_element = q.dequeue();
    std::cout << "Dequeued element: " << dequeued_element << std::endl;

    q.display(); // Display the queue again after dequeue

    std::cout << "New front element is: " << q.peek() << std::endl;

    return 0;
}