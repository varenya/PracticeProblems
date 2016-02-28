#include <stdio.h>
#include <stdlib.h>

void findMax(int a[],int n,int * index){
	int i,diff; 
	for(i=1;i<n;i++){
		diff = a[i]-a[i-1];
		if(diff < 0){
			*index = i-1;
			break;
		}
	}
}

int binarySearch(int a[],int low,int high)
{
	if(low == high)
		return a[low];
	else if( ( (low+1) == high ) && ( a[low] > a[high] )){
         	return a[low];
	}
	else if( ( (low+1) == high ) && ( a[high] > a[low] )){
		a[high];
	}
	int mid = (low+high)/2;
	if( a[mid] > a[mid-1] && a[mid] < a[mid+1] )
		return binarySearch(a,mid+1,high);
	else if( a[mid] < a[mid-1] && a[mid] > a[mid+1] )
		return binarySearch(a,low,mid-1);
	else
		return a[mid];

}

int main(void){
	int a[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
	int b[] = {10, 20, 30, 40, 50};
	int c[] = {120, 100, 80, 20, 0};
	int n1 = sizeof(a)/sizeof(a[0]);
	int n2 = sizeof(b)/sizeof(b[0]);
	int n3 = sizeof(c)/sizeof(c[0]);
	int index = n1-1;
	findMax(a,n1,&index);
	printf("%d \n",a[index]);
	index = n2-1;
	findMax(b,n2,&index);
	printf("%d \n",b[index]);
	findMax(c,n3,&index);
	printf("%d \n",c[index]);
	printf("%d \n",binarySearch(a,0,n1-1));
	printf("%d \n",binarySearch(b,0,n2-1));
	printf("%d \n",binarySearch(c,0,n3-1));
	return 0;
}
