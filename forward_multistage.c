#include <stdio.h>

#define MAX 10
#define INF 999

int main()
{
    int cost[MAX][MAX], dist[MAX], path[MAX];
    int n, i, j, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    dist[n-1] = 0;

    for(i = n-2; i >= 0; i--)
    {
        min = INF;

        for(j = i+1; j < n; j++)
        {
            if(cost[i][j] != INF && cost[i][j] + dist[j] < min)
            {
                min = cost[i][j] + dist[j];
                path[i] = j;
            }
        }

        dist[i] = min;
    }

    printf("\nMinimum cost from source to destination: %d\n", dist[0]);

    printf("Path: 0");
    i = 0;

    while(i != n-1)
    {
        i = path[i];
        printf(" -> %d", i);
    }

    return 0;
}
