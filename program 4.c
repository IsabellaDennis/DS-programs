#include <stdio.h>

#define SIZE 5   // Size of the circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to check if queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Function to insert an element (enqueue)
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is FULL!\n");
        return;
    }

    // If queue is empty, set front to 0
    if (front == -1)
        front = 0;

    // Move rear circularly and insert the element
    rear = (rear + 1) % SIZE;
    queue[rear] = value;

    printf("%d inserted into the queue\n", value);
}

// Function to delete an element (dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }

    int deleted = queue[front];
    printf("%d deleted from the queue\n", deleted);

    // If only one element was present, reset queue
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;  // Move front circularly
}

// Function to display queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Function to count total elements
int count() {
    if (isEmpty())
        return 0;

    if (rear >= front)
        return rear - front + 1;
    else
        return SIZE - front + rear + 1;
}

// Main function — menu-driven program
int main() {
    int choice, value;

    while (1) {
        printf("\n=== Circular Queue Menu ===\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display Queue\n");
        printf("4. Count Elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Total elements: %d\n", count());
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

