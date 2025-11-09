// Kruskal’s algorithm for finding the minimum cost spanning tree using the Disjoint set data structure


#include <stdio.h>

#define MAX 10

// Edge structure
struct Edge {
    int u, v, weight;
};

// Disjoint Set (Union-Find) functions
int parent[MAX];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); // Path compression
}

void unionSet(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) parent[py] = px;
}

int main() {
    int n, e, i, j, count = 0, totalCost = 0;
    struct Edge edges[MAX], result[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Initialize disjoint set
    for (i = 0; i < n; i++) parent[i] = i;

    // Kruskal's algorithm
    while (count < n - 1) {
        int min = 10000, u = -1, v = -1;
        for (i = 0; i < e; i++) {
            int setU = find(edges[i].u);
            int setV = find(edges[i].v);
            if (setU != setV && edges[i].weight < min) {
                min = edges[i].weight;
                u = edges[i].u;
                v = edges[i].v;
            }
        }

        if (u != -1 && v != -1) {
            unionSet(u, v);
            result[count].u = u;
            result[count].v = v;
            result[count].weight = min;
            totalCost += min;
            count++;
        }
    }

    printf("\nMinimum Spanning Tree edges:\n");
    for (i = 0; i < n - 1; i++)
        printf("%d - %d : %d\n", result[i].u, result[i].v, result[i].weight);

    printf("Total cost of MST: %d\n", totalCost);

    return 0;
}



/*
--- Sample Output for Kruskal's MST ---
Enter number of vertices: 4
Enter number of edges: 5
Enter edges (u v weight):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Minimum Spanning Tree edges:
2 - 3 : 4
0 - 3 : 5
0 - 1 : 10
Total cost of MST: 19
*/
