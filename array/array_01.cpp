#include <bits/stdc++.h>

using namespace std;

// Function to reverse an Array 

// This Function is good enough and does the Job when we want to reverse complete array
void reverse(int *A,int n){
	int temp;
	for(int i=0;i<n/2;i++){
		temp =A[n-i-1];
		A[n-i-1]=A[i];
		A[i]=temp;
	}
	return ;
	
	// Time Complexity  : O(n)
}


// But what if we want to reverse only the elements from index i to index j
void reverse(int *A,int i,int j){
	int temp;
	while(i<j){
		temp=A[j];
		A[j]=A[i];
		A[i]=temp;
		i++;
		j--;
	}
	
	// Time Complexity  : O(n)
}

void rreverse(int *A,int i,int j){
	if(i>=j) return;
	int temp;
	temp=A[j];
	A[j]=A[i];
	A[i]=temp;
	rreverse(A,i+1,j-1);
	
	// Time Complexity  : O(n)
	// Recursive
}

void reverseString(string &A){
	char temp;
	for(int i=0;i<(int)A.length()/2;i++){
		temp = A[(int)A.length()-1-i];
		A[A.length()-1-i]=A[i];
		A[i]=temp;
	}
	// Time Complexity  : O(n)
}

void printArray(int *A,int n){
	for(int i=0;i<n;i++){ 
		cout<<A[i]<<" ";	
	}
	cout<<endl;
}
int main(){
	
	int n;
	int *A;
	cin>>n;
	A = new int[n];
	for(int i=0;i<n;i++){ 
		cin>>A[i];	
	}
	rreverse(A,0,n-1);
	printArray(A,n);
    string s;
    cin>>s;
    reverseString(s);
    cout<<s;
	delete[] A;
	return 0;
}
