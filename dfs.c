#include <stdio.h>
#define MAX 10

int graph[MAX][MAX], visited[MAX], n;

void dfs(int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;

    for(i = 0; i < n; i++) {
        if(graph[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
  // Initialize visited array
    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    dfs(0);  

    return 0;
}
         
