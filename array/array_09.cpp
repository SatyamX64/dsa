#include <bits/stdc++.h>

using namespace std;

// Given a Array of size N and a integer K
// You have to add or subtract K from each Element once
// No Element can be less than 0 after modification
// Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.


// Approach 1 - Absolutely Terrible Brute Force 
// Assume 1 to increase by K and 0 to decrease by K (when possible, i.e A[i] >= k)
// Using Power Set Algo (i.e Bit Manipulation) find all combinations of 1,0 for this n sized array
// Find the difference b/w max and min height of tower for each combo
// Take the best of the lot as result
// Time Complexity : O(2^n), not practical

int getMinDiff(int A[],int n,int k){
    sort(A,A+n);
    int minDiff = A[n-1] - A[0]; // We can just add k to both, no difference
    int small = A[0]+k;
    int big = A[n-1]-k;
    if (small > big) 
       swap(small, big); 
    for(int i = 1;i<n-1;i++){
		if(A[i]-k>small || A[i]+k<big) continue; // Bas chotta ho skta hai, bas bada ho skta hai, ya kuch nahi ho sakta
		int res1 = big-(A[i]-k);
		int res2 = A[i]+k-small;
		if(res1>res2){
			big = A[i]+k;
		}else {
			small = A[i]-k;
			break; 
			// Once A[i]-k becomes min, then A[j]-k >= A[i]-k, where j>i (since array is sorted) so, that means no change will occur in min
			// and since we don't want to increase max we will simply perform subtract 'k' operation on each subsequent tower
			// Inshort we don't need to check anymore after this
		}
	}
	
	
	return min(minDiff,big-small);	
	// Greedy Approach 
	// O(nlogn) Complexity
	/* Doesn't work for many test cases like : 
	 * 4  
     * 10
     * 6 1 9 1 1 7 9 5 2 10 */
    // If we change min(minDiff,big-small) with only big-small
    // Then it fails for more test cases, like : 
    /*
     * 5
     * 10
     * 3 4 5 5 6 8 8 9 10 10  
     */
    
}

void printArray(int A[],int n){
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return ;
}

int main(){
	
	int n,k;
	int *A;
	cin>>k>>n;
	A = new int[n];
	for(int i=0;i<n;i++){  
		cin>>A[i];	
	}
	int res = getMinDiff(A,n,k);
	cout<<res;
	delete[] A;
	return 0;
}




