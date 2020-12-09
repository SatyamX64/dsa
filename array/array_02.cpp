#include <bits/stdc++.h>

using namespace std;

// Program to find the Maximum and Minimum of Array 

struct Pair {  // we often use structures when we need to return multiple values
	int min;
	int max;
};

struct Pair getMinMax(int A[],int n){
	struct Pair pair;
    pair.max = A[0];
    pair.min = A[0];
	if (n == 1)     
        return pair; 
	for(int i=1;i<n;i++){
		if(A[i] >pair.max){
			pair.max =A[i];
		}
		else if(A[i]<pair.min){
			pair.min =A[i];
		}
	}
	return pair; 
	// O(n) Complexity
	// Around n Comparisons in Best Case (Asc Sorted Array)
	// Around 2n Comparisons in worst Case (Desc Sorted Array)
	
}


struct Pair getMinMax(int A[],int low,int high){
	struct Pair pair;
	if(low==high){
		pair.max = A[low];
		pair.min = A[low];
		return pair;
	}
	if(high==low+1){
		if(A[low]>A[high]){
		    pair.max = A[low];
		    pair.min = A[high];
		} else {
			pair.max = A[high];
			pair.min = A[low];
		}
		return pair;
	}
	
	struct Pair pair1 = getMinMax(A,low,(low+high)/2);
	struct Pair pair2 = getMinMax(A,(low+high)/2+1,high);
	if(pair1.max>pair2.max) pair.max = pair1.max;
	else pair.max = pair2.max;
	if(pair1.min<pair2.min) pair.min = pair1.min;
	else pair.min = pair2.min;
    return pair;
    
    // Tournament or Divide and Conquer Method
    // Complexity : {Let T(n) be the Number of Comparisons} 
    // T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2
    // T(2) = 1 
    // T(1) = 0
    // if n is power of 2 , then floor = ceil, So
    // T(n) = 2*T(n/2) + 2 ==> 3n/2-2 (Using maths idk)
    // i.e 3n/2-2 comparisons when n is even and a few more if odd 
}

struct Pair getMinMaxL(int arr[], int n) 
{ 
    struct Pair pair;     
    int i; 
     
    // If array has even number of elements 
    // then initialize the first two elements 
    // as minimum and maximum 
    if (n % 2 == 0) 
    { 
        if (arr[0] > arr[1])     
        { 
            pair.max = arr[0]; 
            pair.min = arr[1]; 
        } 
        else
        { 
            pair.min = arr[0]; 
            pair.max = arr[1]; 
        } 
         
        // Set the starting index for loop 
        i = 2; 
    } 
     
    // If array has odd number of elements 
    // then initialize the first element as 
    // minimum and maximum 
    else
    { 
        pair.min = arr[0]; 
        pair.max = arr[0]; 
         
        // Set the starting index for loop 
        i = 1; 
    } 
     
    // In the while loop, pick elements in 
    // pair and compare the pair with max 
    // and min so far 
    while (i < n - 1) 
    {         
        if (arr[i] > arr[i + 1])         
        { 
            if(arr[i] > pair.max)     
                pair.max = arr[i]; 
                 
            if(arr[i + 1] < pair.min)         
                pair.min = arr[i + 1];     
        } 
        else       
        { 
            if (arr[i + 1] > pair.max)     
                pair.max = arr[i + 1]; 
                 
            if (arr[i] < pair.min)         
                pair.min = arr[i];     
        } 
         
        // Increment the index by 2 as 
        // two elements are processed in loop 
        i += 2; 
    }         
    return pair;
    
    // if n is even : 
    // 		1 (Initial Comaprison) + 3(1 to compare a[i] & a[i+1] & 2 to compare with min & max)*((n-2)/2)
    // if n is odd : 
    //      3*(n-1)/2 
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
	struct Pair pair = getMinMaxL(A,n);
	cout<<pair.min<<" "<<pair.max;
	delete[] A;
	return 0;
}
