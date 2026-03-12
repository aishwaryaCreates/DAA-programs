#include <stdio.h>
#define n 5
int main() 
{
   int cost[n][n], visited[n] = {0};
   int i, j, ne = 1, a, b, min, mincost = 0;
    printf("Enter the cost matrix:\n");
	 for(i=0; i<n; i++)
	  {
	   for(j=0; j<n; j++)
	    {
		 scanf("%d", &cost[i][j]);
		 	if(cost[i][j]==0)
			 	cost[i][j] = 999;
		}
  }
    visited[0] = 1;
    while(ne < n)
    {
      min = 999;
	  for(i=0; i<n; i++)
      {
       for(j=0; j<n; j++)
       {
        if(cost[i][j] < min)
        {
         if(visited[i]!= 0)
         {
   	      min = cost[i][j];
   	      a = i;
   	      b = j;
		 }
	    }
   	}
 }
 if(visited[b]==0)
 {
 	printf("\n Edge %d: (%d %d)cost: %d", ne++, a,b, min);
 	mincost = mincost + min;
 	visited[b] = 1;
 }
 cost[a][b] = cost[b][a] = 999;
}
printf("\n Minimum cost = %d", mincost);
return 0;
}
