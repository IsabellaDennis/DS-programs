#include <stdio.h>

#define INF 9999
#define MAX 10

int main() {
    int G[MAX][MAX];
    int visited[MAX] = {0};
    int V;
    int i, j, no_edge = 0, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &G[i][j]);
            if (G[i][j] == 0)
                G[i][j] = INF; // Replace 0 with INF (no connection)
        }
    }

    // Start from the first vertex
    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    // Repeat until we have V-1 edges
    while (no_edge < V - 1) {
        int min = INF;
        int a = -1, b = -1;

        for (i = 0; i < V; i++) {
            if (visited[i]) { // vertex already in MST
                for (j = 0; j < V; j++) {
                    if (!visited[j] && G[i][j] < min) {
                        min = G[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", a, b, min);
        total += min;
        visited[b] = 1;
        no_edge++;
    }

    printf("\nTotal Minimum Cost = %d\n", total);

    return 0;
}
