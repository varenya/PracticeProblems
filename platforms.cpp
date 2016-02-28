#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>

using namespace std;
int min_platforms(int arr[],int dep[],int n);
void printArray(int arr[],int n);
int main()
{
	int arr[] = {900, 940, 950, 1100, 1500, 1800};
	int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Minimum Number of Platforms Required = " << min_platforms(arr, dep,n);
	return 0;
}

int min_platforms(int arr[],int dep[],int n){

	cout << "Size " << n << endl;
	sort(arr,arr+n);
	sort(dep,dep+n);

	printArray(arr,n);
	printArray(dep,n);

	int i=1,j=0,platform=1,minplatform=1;
	
	while(i < n && j < n){
		if( arr[i] < dep[j] ){
			platform++;
			i++;
			if(platform > minplatform)
				minplatform = platform;
		}
		else{
			platform--;
			j++;
		}
	}
	return minplatform;
}

void printArray(int arr[],int n){
	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
	cout << endl;
}
