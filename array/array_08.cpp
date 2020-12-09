#include <bits/stdc++.h>

using namespace std;

// Find the largest Sum possible in a contgiuous subarray
// Kadane's Algorithm


// Approach 1 - Brute Force
/* Use 3 Loops
 * for(i=0;i<n;i++){
 * 	for(j=i;j<n;j++){
 * 	 for(k=i;k<=j;k++)
 * 		sum +=A[k];
 *   if(sum>max) max=sum;
 *  }
 * }
 * This way we will have the Sum for all possible Subsets, then we will pick the best one out
 * Time Complexity - O(n^3)
*/

// Approach 2 - Optimized Brute Force
/* Use 2 Loops
 * for(i=0;i<n;i++){
 * 	for(j=i;j<n;j++){
 * 	 sum +=A[j];
 *   if(sum>max) max=sum;
 *  }
 * }
 * Optimized in the sense, that we count the sum as we iterate j rather than using extra loop
 * This way we will have the Sum for all possible Subsets, then we will pick the best one out
 * Time Complexity - O(n^2)
*/
 
// Approach 3 - Kadane's Algo
/* int sum = 0;
 * for(int i = 0;i<n;i++){
 * 	if including A[i] in sum (assuming its also positive) increases it then include it  // i.e when A[i] is >= 0 
 *  else {
 *   // We are here than it means either/both A[i] or sum is negative
 * 			if A[i] is greater than the current sum then set sum = A[i] and move on  // i.e if sum is more negative 
 * 			else if A[i] is smaller than sum then adding A[i] to sum still keeps it greater than A[i] so add it and move on 
 *          else if A[i] == sum , do nothing since both are negative just move on
 *  }
 * Keep track of changes in sum, its best possible value is the answer
 * Time Complexity - O(n)
*/

int maxSubArray(int A[],int n){
    
    int sum=A[0],max=A[0];
    for(int i=1;i<n;i++){
		if(A[i]>=0 && sum>=0) sum+=A[i];
		else {
			if(A[i]>sum) sum = A[i];
			else if(A[i]<sum){
				if(sum>max) max =sum;
				sum += A[i];
			}
		}
		if(sum>max) max=sum;
	}
	return max;

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
	int res = maxSubArray(A,n);
	cout<<res;
	delete[] A;
	return 0;
}




