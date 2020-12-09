#include <bits/stdc++.h>

using namespace std;

// Program to find the Kth Maximum/Minimum of Array if all elements are distinct


int getKthMin(int A[],int l,int r,int k){
	// Brute Force Approach, not desirable here
	// Sort the Array
	// A[k-1] is the kth Minimum element 
	// A[n-k-1] is the Kth Maximum element 
	// Time Complexity : Same as type of sorting used, mostly O(nlogn) 
	 
    sort(A+l,A+r);
    return A[l+k-1];
    
}
// Rest approach requires knowledge of Heap and are a little advance so I will skip them for now

int main(){
	
	int n;
	int *A;
	cin>>n;
	A = new int[n];
	for(int i=0;i<n;i++){ 
		cin>>A[i];	
	}
	int k;
	cin>>k;
	int res = getKthMin(A,0,n,k);
	cout<<res;
	delete[] A;
	return 0;
}
