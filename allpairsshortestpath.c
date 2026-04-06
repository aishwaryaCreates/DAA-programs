#include <stdio.h>
#define MAX 100
#define INF 99999

int i, j;

// Print function
void printSolution(int n, int dist[MAX][MAX]) {
    printf("\nShortest distance matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd Warshall function
void floydWarshall(int n, int graph[MAX][MAX]) {
    int dist[MAX][MAX];
    int k;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    // Algorithm
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(dist[i][k] != INF && dist[k][j] != INF &&
                   dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(n, dist);
}

// Main function
int main() {
    int n, graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(n, graph);

    return 0;
}
