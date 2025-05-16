#include <stdio.h>
#include <stdlib.h>

#define V 5
#define E 7

struct Edge {
    int src, dest, weight;
};
struct Graph {
    struct Edge edges[E];
};
int parent[V];
int find(int i) {
    while (i != parent[i])
        i = parent[i];
    return i;
}
void unionSet(int u, int v) {
    parent[u] = v;
}
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}
void kruskalMST(struct Graph* graph) {
    struct Edge result[V];
    int e = 0;
    for (int i = 0; i < V; i++)
        parent[i] = i;

    qsort(graph->edges, E, sizeof(graph->edges[0]), compare);

    for (int i = 0; i < E && e < V - 1; i++) {
        int u = find(graph->edges[i].src);
        int v = find(graph->edges[i].dest);

        if (u != v) {
            result[e++] = graph->edges[i];
            unionSet(u, v);
        }
    }
    printf("Edge \tWeight\n");
    for (int i = 0; i < e; i++)
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
}
int main(){
    struct Graph graph = {
        .edges = {
            {0, 1, 15},
            {0, 2, 8},
            {0, 3, 12},
            {1, 3, 10},
            {2, 3, 5},
            {1, 2, 6},
            {2, 4, 9}
        }
    };

    kruskalMST(&graph);

    return 0;
}

/* output:
Edge 	Weight
2 - 3 	5
1 - 2 	6
0 - 2 	8
2 - 4 	9 */
