#include <stdio.h>
#include <stdlib.h>

#define V 6

void DFS(int graph[V][V], int visited[], int topoSort[], int vertex, int *index) {
    visited[vertex] = 1;
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, visited, topoSort, i, index);
        }
    }
    topoSort[(*index)++] = vertex;
}
void topologicalSort(int graph[V][V]) {
    int visited[V] = {0};
    int topoSort[V];
    int index = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(graph, visited, topoSort, i, &index);
        }
    }
    printf("Topological Sort: ");
    for (int i = V - 1; i >= 0; i--) {
        printf("%d ", topoSort[i]);
    }
    printf("\n");
}
int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };
    topologicalSort(graph);
    return 0;
}

/* output:
Topological Sort: 0 1 2 3 4 5 */
