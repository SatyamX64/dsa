#include <bits/stdc++.h>

using namespace std;

// Given a Array of size N 
// Where A[i] represents the number of moves you can make forward
// 0 <= A[i] <= 10^7
// Find out the minimum number of moves required to get to the last element.

int minJumps(int A[],int n){
    int steps = 1,index=0;
    while(A[index]+index < n-1){
		int pos = 1;
		int fi=0;
		int maxRange = 0;
		while(pos<=A[index]){
			if(A[index+pos]==0) {
				pos++;
				continue;
			}			
			if(A[index+pos]+pos>maxRange) { 
				maxRange =A[index+pos]+pos;
				fi=index+pos;
				}
			pos++;
		}
		if(fi==0) return -1;
		else index=fi;
		steps++;
		cout<<index<<" "<<steps<<endl;
	}
    return steps;	
		
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
	int res = minJumps(A,n);
	cout<<res;
	delete[] A;
	return 0;
}




