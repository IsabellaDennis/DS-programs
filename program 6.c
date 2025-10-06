#include <stdio.h>

int main() {
    int sizeA, sizeB, maxElement = 0, choice;

    // Input Set A
    printf("Enter number of elements in Set A: ");
    scanf("%d", &sizeA);
    int setA[sizeA];
    printf("Enter elements of Set A: ");
    for (int i = 0; i < sizeA; i++) {
        scanf("%d", &setA[i]);
        if (setA[i] > maxElement) maxElement = setA[i];
    }

    // Input Set B
    printf("Enter number of elements in Set B: ");
    scanf("%d", &sizeB);
    int setB[sizeB];
    printf("Enter elements of Set B: ");
    for (int i = 0; i < sizeB; i++) {
        scanf("%d", &setB[i]);
        if (setB[i] > maxElement) maxElement = setB[i];
    }

    // Create bit arrays
    int setA_bs[maxElement + 1];
    int setB_bs[maxElement + 1];
    for (int i = 0; i <= maxElement; i++) setA_bs[i] = setB_bs[i] = 0;
    for (int i = 0; i < sizeA; i++) setA_bs[setA[i]] = 1;
    for (int i = 0; i < sizeB; i++) setB_bs[setB[i]] = 1;

    int result[maxElement + 1];
    int i;

    // Menu-driven operations
    do {
        printf("\n--- Set Operations Menu ---\n");
        printf("1. Union (A U B)\n");
        printf("2. Intersection (A ∩ B)\n");
        printf("3. Difference (A - B)\n");
        printf("4. Display Sets A and B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Union
                for (i = 0; i <= maxElement; i++)
                    result[i] = setA_bs[i] || setB_bs[i];

                printf("Union (A U B) = { ");
                for (i = 0; i <= maxElement; i++)
                    if (result[i]) printf("%d ", i);
                printf("}\nBit string: ");
                for (i = 0; i <= maxElement; i++)
                    printf("%d", result[i]);
                printf("\n");
                break;

            case 2: // Intersection
                for (i = 0; i <= maxElement; i++)
                    result[i] = setA_bs[i] && setB_bs[i];

                printf("Intersection (A ∩ B) = { ");
                for (i = 0; i <= maxElement; i++)
                    if (result[i]) printf("%d ", i);
                printf("}\nBit string: ");
                for (i = 0; i <= maxElement; i++)
                    printf("%d", result[i]);
                printf("\n");
                break;

            case 3: // Difference
                for (i = 0; i <= maxElement; i++)
                    result[i] = setA_bs[i] && !setB_bs[i];

                printf("Difference (A - B) = { ");
                for (i = 0; i <= maxElement; i++)
                    if (result[i]) printf("%d ", i);
                printf("}\nBit string: ");
                for (i = 0; i <= maxElement; i++)
                    printf("%d", result[i]);
                printf("\n");
                break;

            case 4: // Display Sets A and B
                printf("Set A = { ");
                for (i = 0; i <= maxElement; i++)
                    if (setA_bs[i]) printf("%d ", i);
                printf("}\nBit string: ");
                for (i = 0; i <= maxElement; i++)
                    printf("%d", setA_bs[i]);
                printf("\n");

                printf("Set B = { ");
                for (i = 0; i <= maxElement; i++)
                    if (setB_bs[i]) printf("%d ", i);
                printf("}\nBit string: ");
                for (i = 0; i <= maxElement; i++)
                    printf("%d", setB_bs[i]);
                printf("\n");
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
