#include <bits/stdc++.h>

using namespace std;

// Given a Array of size N+1 
// where all the elements are from [1,n]
// and there is only one number that is repeated. Find that number

// Flyod's Tortoise and Hare Problem

// Brute Force Approach 1 :
// Sort the Array and find what adjacent elements are equal
// This will have : O(nlogn)

// Brute Force Approach 2 :
// Do hashing 
// This will have time : O(n) , space : O(n)

// Constraints that make the Problem meaningful
/*
   * How can we prove that at least one duplicate number must exist in nums? >> Pigeon Hole Principle
   * Can you solve the problem without modifying the array nums?
   * Can you solve the problem using only constant, O(1) extra space?
   * Can you solve the problem with runtime complexity less than O(n2)?
*/



int findDuplicateV1(int A[],int n){
	int sum = 0;
	for(int i = 0;i<n;i++){
		sum +=A[i];
	}
	n--;
	return sum- (n*(n+1)/2);
	// Works well only when you are assured that a number is atmost repeated twice
	// So it wont work for :
	/*
	 * 5
	 * 1 2 2 2 3 
	 */
}


int findDuplicateV2(int A[],int n){
	
	for(int i = 0;i<n;i++){
		if(A[abs(A[i])-1]>0) A[abs(A[i])-1]*=-1;
		else return abs(A[i]);
	}
	return 0;
	// Time : O(n), Space : O(1)
	// Approach : Since we know all A[i] is b/w 1-n therefore it means all are also valid index
	// So we just make the value at the visited points as negative, and incase we encounter a negative digit while jumping to an index
	// Then we know it is repeated
	// But this modifies the array 
}

int findDuplicateV3(int nums[],int n)
{
	if (n > 1)
	{
		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}
	return -1;
	// Time : O(n), Space : O(1)
	// The Floyd's Fare and Turtle Algorithm
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
	int res = findDuplicateV3(A,n);
	cout<<res;
	delete[] A;
	return 0;
}




