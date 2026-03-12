#include <stdio.h>
int main()
{
int arr[] = {4, 7, 1, 9, 2};
int n = sizeof(arr)/sizeof(arr[0]), i;
int max = arr[0];
int min = arr[0];
for(i = 1; i<n; i++)
{
	if(arr[i]>max)
	max = arr[i];
	if(arr[i] < min)
	min = arr[i];
}
printf("Maximum = %d\n", max);
printf("Minimum = %d\n", min);
return 0;
}
