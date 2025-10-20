#include <stdio.h>
#define MAX 10

int main() {
    int n, cost[MAX][MAX], visited[MAX] = {0};
    int edges = 0, totalCost = 0, a, b, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    visited[0] = 1;  // start from vertex 0

    printf("\nEdges in MST:\n");

    while(edges < n-1) {
        min = 0; a = b = -1;

        // Find smallest edge from visited to unvisited
        for(int i=0;i<n;i++)
            if(visited[i])
                for(int j=0;j<n;j++)
                    if(!visited[j] && cost[i][j] != 0 && (min == 0 || cost[i][j] < min)) {
                        min = cost[i][j]; a = i; b = j;
                    }

        if(a != -1 && b != -1) {
            printf("%d -> %d  cost = %d\n", a, b, min);
            visited[b] = 1;
            totalCost += min;
            edges++;
        }
    }

    printf("\nMinimum cost = %d\n", totalCost);
    return 0;
}
