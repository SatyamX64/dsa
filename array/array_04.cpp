#include <bits/stdc++.h>

using namespace std;

// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
// The Dutch National Flag Problem
// Three Way partition

void funV1(int A[],int n){
	 
    sort(A,A+n);
    return ;
    // Brute Force Approach 
	// Use any sorting Algo on the Array
	// Time Complexity  : O(nlogn)
}

void funV2(int A[], int n)
{
    // Variables to maintain the count of 0's, 
    // 1's and 2's in the array
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == 0)
            count0++;
        if (A[i] == 1)
            count1++;
        if (A[i] == 2)
            count2++;
    }
 
    // Putting the 0's in the array in starting.
    for (int i = 0; i < count0; i++) 
        A[i] = 0;
     
    // Putting the 1's in the array after the 0's.
    for (int i = count0; i < (count0 + count1); i++) 
        A[i] = 1;
     
    // Putting the 2's in the array after the 1's
    for (int i = (count0 + count1); i < n; i++) 
        A[i] = 2;
     
    return;
    
    //Time Complexity : O(n)
    //Space Complexity  : O(1)
    //Iterates Twice
}

void funV3(int A[],int n) {
	int forward = 0, backward = n-1;
	int pivot = 1;
	for(int i = 0;i<n;i++) {
		if(A[i]<pivot){
			swap(A[i],A[forward]);
			forward++;
		}
	}
	
	for(int i = n-1;i>=forward;i--){
		if(A[i]>pivot){
			swap(A[i],A[backward]);
			backward--;
		}
	}
	
	return ;
	// Time Complexity : O(n)
	// Iterates Twice only for worst case (i.e All Elements are greater than Pivot)
	// Iterates Once for Best Case (i.e All Elements are smaller than Pivot)
	
}

void funV4(int A[], int n) 
{ 
    int lo = 0; 
    int hi = n - 1; 
    int mid = 0; 
  
    // Iterate till all the elements 
   
    while (mid <= hi) { 
        switch (A[mid]) { 
  
        // If the element is 0 
        case 0: 
            swap(A[lo++], A[mid++]); 
            break; 
  
        // If the element is 1 . 
        case 1: 
            mid++; 
            break; 
  
        // If the element is 2 
        case 2: 
            swap(A[mid], A[hi--]); 
            break; 
        } 
    } 
    // Time Complexity : O(n)
    // Iterates only once
    // Three Way partition or Dutch Flag Problem Standard Algo
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
	funV4(A,n);
	printArray(A,n);
	delete[] A;
	return 0;
}



// Trivia : These are Sorting Methods when only 2 Unique Elements are Present


void sort2FunV1(int A[], int size)  
{  
	 
    /* Initialize left and right indexes */
    int left = 0, right = size-1;  
  
    while (left < right)  
    {  
        /* Increment left index while we see 0 at left */
        while (A[left] == 0 && left < right)  
            left++;  
  
        /* Decrement right index while we see 1 at right */
        while (A[right] == 1 && left < right)  
            right--;  
  
        /* If left is smaller than right then there is a 1 at left  
        and a 0 at right. Exchange arr[left] and arr[right]*/
        if (left < right)  
        {  
            A[left] = 0;  
            A[right] = 1;  
            left++;  
            right--;  
        }  
    }  
   // Applicable only when 2 unique Numbers are used
   // Complexity : O(n)
   // Iterates only Once
}  

void sort2FunV2(int A[],int size) { 
    
    int type0 = 0; 
    int type1 = size - 1; 
      
    while(type0 < type1) 
    { 
        if(A[type0] == 1) 
        { 
            swap(A[type0],A[type1]); 
            type1--; 
        } 
        else
        type0++; 
    }
    return ;
    // Applicable only when 2 unique numbers are Used
    // Same Idea as SortFun, just implemented a little differently
    // O(n), Single Iteration 
}
