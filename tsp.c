#include <stdio.h>
#include <limits.h>

#define MAX 10

int n, graph[MAX][MAX], visited[MAX];
int i, j;

// Min function
int min(int a, int b) {
    return (a < b) ? a : b;
}

// TSP function
int tsp(int city, int count, int cost) {
    // If all cities visited, return to starting city
    if(count == n && graph[city][0]) {
        return cost + graph[city][0];
    }

    int ans = INT_MAX;

    for(i = 0; i < n; i++) {
        if(!visited[i] && graph[city][i]) {
            visited[i] = 1;

            int newAns = tsp(i, count + 1,
                            cost + graph[city][i]);

            ans = min(ans, newAns);

            visited[i] = 0;  // backtrack
        }
    }

    return ans;
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize visited array
    for(i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;  // start from city 0

    int result = tsp(0, 1, 0);

    printf("Minimum travelling cost: %d\n", result);

    return 0;
}
