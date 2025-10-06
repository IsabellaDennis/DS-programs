#include <stdio.h>
#define SIZE 5  

int queue[SIZE];
int front = -1, rear = -1;

   
int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front);
}


int isEmpty() {
    return (front == -1);
}


void enqueue(int value) {
    if (isFull()) {
        printf("Queue is FULL!\n");
        return;
    }
    if (front == -1) front = 0;  
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("%d inserted\n", value);
}


void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }
    int data = queue[front];
    if (front == rear) {
        
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    printf("%d deleted\n", data);
}


void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
} 


int count() {
    if (isEmpty()) return 0;
    if (rear >= front) return rear - front + 1;
    return (SIZE - front + rear + 1);
}


int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Count elements\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
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
                printf("Total elements = %d\n", count());
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

