//Set operations (Union, Intersection and Difference) using Bit String.

#include <stdio.h>

#define MAX 10

// Display a set using its bit array
void displaySet(int set[], int n, int universal[]) {
    printf("{ ");
    for (int i = 0; i < n; i++)
        if (set[i]) printf("%d ", universal[i]);
    printf("}\n");
}

// Union
void unionSet(int A[], int B[], int C[], int n) {
    for (int i = 0; i < n; i++) C[i] = A[i] | B[i];
}

// Intersection
void intersectionSet(int A[], int B[], int C[], int n) {
    for (int i = 0; i < n; i++) C[i] = A[i] & B[i];
}

// Difference A - B
void differenceSet(int A[], int B[], int C[], int n) {
    for (int i = 0; i < n; i++) C[i] = A[i] & (1 - B[i]);
}

// Input a set
void inputSet(int set[], int n, int universal[], char setName) {
    int size;
    printf("Enter size of set %c: ", setName);
    scanf("%d", &size);
    printf("Enter elements of set %c:\n", setName);
    for (int i = 0; i < size; i++) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < n; j++)
            if (universal[j] == x) set[j] = 1;
    }
}

int main() {
    int n;
    printf("Enter size of universal set (max %d): ", MAX);
    scanf("%d", &n);

    int universal[MAX];
    printf("Enter elements of universal set:\n");
    for (int i = 0; i < n; i++) scanf("%d", &universal[i]);

    int A[MAX] = {0}, B[MAX] = {0}, C[MAX] = {0};

    inputSet(A, n, universal, 'A');   // Input set A
    inputSet(B, n, universal, 'B');   // Input set B

    // Perform operations and display results
    unionSet(A, B, C, n);
    printf("\nA ∪ B = "); displaySet(C, n, universal);

    intersectionSet(A, B, C, n);
    printf("A ∩ B = "); displaySet(C, n, universal);

    differenceSet(A, B, C, n);
    printf("A - B = "); displaySet(C, n, universal);

    return 0;
}


/*
--- Sample Output for Set Operations ---
Enter size of universal set (max 10): 5
Enter elements of universal set:
1 2 3 4 5
Enter size of set A: 3
Enter elements of set A:
1 3 5
Enter size of set B: 2
Enter elements of set B:
2 3

A ∪ B = { 1 2 3 5 }
A ∩ B = { 3 }
A - B = { 1 5 }
*/
