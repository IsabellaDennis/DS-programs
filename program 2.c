//Singly Linked Stack-- Creation, Insertion, Deletion, Traversal, Count. 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push (Insertion)
void push(int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
}

// Pop (Deletion)
void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d popped from stack\n", top->data);
    struct Node *temp = top;
    top = top->next;
    free(temp);
}

// Display (Traversal)
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Count elements
void count() {
    int c = 0;
    struct Node *temp = top;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    printf("Total elements in stack: %d\n", c);
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Count\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                count();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}


/* Sample Output:

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Count
5. Exit
Enter choice: 1
Enter value to push: 10
10 pushed to stack

--- Stack Menu ---
Enter choice: 1
Enter value to push: 20
20 pushed to stack

--- Stack Menu ---
Enter choice: 3
Stack elements: 20 10

--- Stack Menu ---
Enter choice: 4
Total elements in stack: 2

--- Stack Menu ---
Enter choice: 2
20 popped from stack

--- Stack Menu ---
Enter choice: 3
Stack elements: 10

--- Stack Menu ---
Enter choice: 5

*/
