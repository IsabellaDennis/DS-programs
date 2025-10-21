#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node (simple — left first, then right)
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (root->left == NULL)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// Traversals
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Delete entire tree
struct Node* deleteTree(struct Node* root) {
    if (root == NULL)
        return NULL;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
    return NULL;
}

// Delete a node by value (replace internal node with rightmost leaf)
struct Node* deleteNode(struct Node* root, int key) {
    if (!root) return NULL;

    if (root->data == key) {
        // Leaf node
        if (!root->left && !root->right) {
            free(root);
            return NULL;
        }
        // Replace with rightmost leaf in left subtree if exists
        if (root->left) {
            struct Node* temp = root->left;
            while (temp->right) temp = temp->right;
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }
        // If no left, replace with leftmost leaf in right subtree
        else if (root->right) {
            struct Node* temp = root->right;
            while (temp->left) temp = temp->left;
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    // Recurse left and right
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);

    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Delete Node by Value\n");
        printf("6. Delete Entire Tree\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 6:
                root = deleteTree(root);
                printf("Tree deleted.\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

