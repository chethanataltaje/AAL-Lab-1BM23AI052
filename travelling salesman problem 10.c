
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void totalCost(int cost[10][10], bool visited[], int currPos, int n,
               int count, int costSoFar, int *ans) {

    if (count == n && cost[currPos][0]) {
        if (*ans > costSoFar + cost[currPos][0]) {
            *ans = costSoFar + cost[currPos][0];
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[currPos][i]) {
            visited[i] = true;
            totalCost(cost, visited, i, n, count + 1, costSoFar + cost[currPos][i], ans);
            visited[i] = false; // Backtrack
        }
    }
}
int tsp(int cost[10][10], int n) {
    bool visited[10] = {false};
    visited[0] = true;
    int ans = INT_MAX;

    totalCost(cost, visited, 0, n, 1, 0, &ans);
    return ans;
}
int main() {
    int cost[10][10] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int n = 4;
    int result = tsp(cost, n);
    printf("Minimum TSP cost: %d\n", result);
    return 0;
}

