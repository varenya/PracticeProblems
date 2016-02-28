#include <stdio.h>
#include <stdlib.h>

int main(void){


	




}


int findWater(int a[],int n){
	int left[n];
	int right[n];
	int water = 0;

	left[0] = arr[0];
	int i = 0;
	for(i=1;i<n;i++)
		left[i] = max(left[i-1],a[i]);
	right[n-1] = arr[n-1];

	for(i=n-2;i>=0;i--)
		right = max(right[i+1],arr[i]);

	int water = 0;

	for(i=0;i<n;i++)
		water += min(left[i],right[i])-arr[i];

	return water;
}
