#include <iostream>
#define R 3
#define C 3

using namespace std;

int findPath(int a[][C],int m,int n,int k){

	if(m < 0 || n < 0) return 0;

	if( m == 0 && n==0) return k == a[m][n];

	return findPath(a,m-1,n,k-a[m][n])+findPath(a,m,n-1,k-a[m][n]);

}


int main(){
	int a[R][C] = { 
			{1,2,3},
			{4,5,6},
			{7,8,9} 
	};
	cout << findPath(a,R-1,C-1,12);
	return 0;
}


