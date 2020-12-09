#include <bits/stdc++.h>

using namespace std;

// Move all the negatives to one side of the Array 

void funV1(int A[], int size)  
{  
	 
    /* Initialize left and right indexes */
    int left = 0, right = size-1;  
  
    while (left < right)  
    {  
        /* Increment left index while we see Negative at left */
        while (A[left] < 0 && left < right)  
            left++;  
  
        while (A[right] > 1 && left < right)  
            right--;  
  
        /* If left is smaller than right then there is a Pos at left  
        and a Neg at right. Exchange arr[left] and arr[right]*/
        if (left < right)  
        {   
			swap(A[left],A[right]); 
            left++;  
            right--;  
        }  
    }  
   // Complexity : O(n)
   // Iterates only Once
}  

void funV2(int A[],int size) { 
    
    int neg = 0; 
    int pos = size - 1; 
      
    while(neg < pos) 
    { 
        if(A[neg] >= 0) 
        { 
            swap(A[neg],A[pos]); 
            pos--; 
        } 
        else
        neg++; 
    }
    return ;
    
    // O(n), Single Iteration 
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
	funV2(A,n);
	printArray(A,n);
	delete[] A;
	return 0;
}




