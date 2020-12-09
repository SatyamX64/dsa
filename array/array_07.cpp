#include <bits/stdc++.h>

using namespace std;

// Cyclically rotate Array by one

void rotate(int A[],int n){
	int i = n-1;
	int last = A[n-1];
	while(i>0){
		A[i] = A[i-1];
		i--;
	}
	A[0]=last;
	return ;
	//Time Complexity : O(n)
} 


void printArray(int A[],int n){
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return ;
}

int main(){
	
	int n;
	int *A;
	cin>>n;
	A = new int[n];
	for(int i=0;i<n;i++){  
		cin>>A[i];	
	}
	rotate(A,n);
	printArray(A,n);
	delete[] A;
	return 0;
}




