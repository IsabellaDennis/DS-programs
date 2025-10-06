#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL, *tail = NULL;

// Insert at beginning
void insertBeg(int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    else
        tail = newNode;
    head = newNode;
    printf("%d inserted at beginning\n", value);
}

// Insert at end
void insertEnd(int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;
    if (tail != NULL)
        tail->next = newNode;
    else
        head = newNode;
    tail = newNode;
    printf("%d inserted at end\n", value);
}

// Delete from beginning
void deleteBeg() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("%d deleted from beginning\n", head->data);
    struct Node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;
    free(temp);
}

// Delete from end
void deleteEnd() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("%d deleted from end\n", tail->data);
    struct Node *temp = tail;
    tail = tail->prev;
    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;
    free(temp);
}

// Display from beginning
void displayFromBeg() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List from beginning: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Display from end
void displayFromEnd() {
    struct Node *temp = tail;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List from end: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Count nodes
void count() {
    int c = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    printf("Total nodes: %d\n", c);
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at beginning\n2. Insert at end\n3. Delete from beginning\n4. Delete from end\n");
        printf("5. Display from beginning\n6. Display from end\n7. Count nodes\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeg(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                deleteBeg();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                displayFromBeg();
                break;
            case 6:
                displayFromEnd();
                break;
            case 7:
                count();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
