#include <stdio.h>
#define MAX 10

int graph[MAX][MAX], visited[MAX], queue[MAX];
int n, front = 0, rear = 0, i, j;

void bfs(int start) {
    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for(i = 0; i < n; i++) {
            if(graph[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) 
        for(j = 0; j < n; j++) 
            scanf("%d", &graph[i][j]);
    bfs(0);
    return 0;
}
