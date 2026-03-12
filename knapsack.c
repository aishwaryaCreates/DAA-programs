#include <stdio.h>
struct Item {
    int weight;
    int profit;
    float ratio;
};
int main() 
{
    int n, i, j, capacity;
    float total_Profit = 0.0;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    printf("Enter weight and profit of each item:\n");
    for (i = 0; i < n; i++) 
	{
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    for (i = 0; i < n - 1; i++) 
	{
        for (j = 0; j < n - i - 1; j++) 
		{
            if (items[j].ratio < items[j + 1].ratio) 
			{
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) 
	{
        if (capacity >= items[i].weight)
		{
            capacity -= items[i].weight;
            total_Profit += items[i].profit;
        } else 
		{
            total_Profit += items[i].ratio * capacity;
            break;
        }
    }
    printf("Maximum profit = %.2f\n", total_Profit);
    return 0;
}

