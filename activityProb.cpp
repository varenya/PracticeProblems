#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>



// end needs to be sorted for the logic to work.
void activites(int start[],int end[],int n){

	int i =0;
	printf("%d ",i);

	for(int j=1;j<n;j++){

		if(start[j] >= end[i]){

			printf("%d ",j);
			i=j;
		}
	}


}

int main()
{
    int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    activites(s, f, n);
    getchar();
    return 0;
}

