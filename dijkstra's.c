#include <stdio.h>
#define n 4
  int main()
  {
    int cost[n][n], distance[n], visited[n] = {0};
 	int i, j, count, min, nextnode, start;
 	printf("Enter the cost matrix:\n");
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<n;j++)
 		{
 			scanf("%d", &cost[i][j]);
			 if(cost[i][j] == 0 && i!=j)
			 cost[i][j] = 999;
		}
	}
	printf("Enter Starting Vertex: ");
	scanf("%d", &start);
	for(i=0; i<n; i++) 
	distance[i] = cost[start][i];
	visited[start] = 1;
	visited[start] = 0;
	count = 1;
	while(count<n-1)
	{
		min = 999;
		for(i=0;i<n;i++)
        {
        	if(distance[i]<min && visited[i]==0)
        	{
        		min = distance[i];
        		nextnode = i;
			}
		}
		visited[nextnode] = 1;
		for(i=0;i<n;i++)
        {
	     if(!visited[i])
	     {
	     	if(min+cost[nextnode][i]<distance[i])	
			{
			 	distance[i] = min + cost[nextnode][i];
			}	 
		 }
	    } 
		count++;
	}
	printf("\n Shortest distances from vertex %d:\n", start);
	for(i=0; i<n; i++)
	printf("%d -> %d = %d\n", start, i, distance[i]);
	return 0;
}
