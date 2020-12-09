#include <bits/stdc++.h>

using namespace std;

// Print the Number of Elements in the Union of Two Sorted Arrays

int Union(int A[], int n, int B[], int m)  
{  
	 
   int p1 =0,p2 =0,count=0;
   cout<<"Union is : ";
   while(p1<n && p2<m) {
	   while(p1 < n-1 && A[p1] == A[p1+1]) p1++;
	   while(p2 < m-1 && B[p2] == B[p2+1]) p2++;

	   if(A[p1]==B[p2]) {
		   cout<<A[p1]<<" ";
		   count++;
		   p1++;
		   p2++;
	   } else if (A[p1]>B[p2] ){
		   cout<<B[p2]<<" ";
		   count++;
		   p2++;
	   } else if (A[p1]<B[p2] ){
		   cout<<A[p1]<<" ";
		   count++;
		   p1++;
	   }
	}
	
	while(p1<n){
		while(p1 < n-1 && A[p1] == A[p1+1]){
		 p1++;
		}
		cout<<A[p1]<<" ";
		p1++;
		count++;
	}
	
	
	while(p2<m) {
		while(p2 < m-1 && B[p2] == B[p2+1]){
		 p2++;
		}
		cout<<B[p2]<<" ";
		p2++;
		count++;
	} 
	
	return count;
	   
   //   Complexity : O(m+n))
   //   Iterates only Once
}  

int Intersection(int A[], int n, int B[], int m)  
{  
	 
   int p1 =0,p2 =0,count=0;
   cout<<"\nIntersection is : ";
   while(p1<n && p2<m) {
	   while(p1 < n-1 && A[p1] == A[p1+1]) p1++;
	   while(p2 < m-1 && B[p2] == B[p2+1]) p2++;

	   if(A[p1]==B[p2]) {
		   cout<<A[p1]<<" ";
		   count++;
		   p1++;
		   p2++;
	   } else if (A[p1]>B[p2] ){
		   p2++;
	   } else if (A[p1]<B[p2] ){
		   p1++;
	   }
	}
	
	while(p1<n){
		while(p1 < n-1 && A[p1] == A[p1+1]){
		 p1++;
		}
		p1++;
	}
	
	
	while(p2<m) {
		while(p2 < m-1 && B[p2] == B[p2+1]){
		 p2++;
		}
		p2++;
	} 
	
	return count;
	   
   //   Complexity : O(m+n))
   //   Iterates only Once
}  

int main(){
	
	int n,m;
	int *A,*B;
	cin>>n>>m;
	A = new int[n];
	B = new int[m];
	for(int i=0;i<n;i++){  
		cin>>A[i];	
	}
	for(int i=0;i<m;i++){  
		cin>>B[i];	
	}
	sort(A,A+n);
	sort(B,B+m);
	int res = Union(A,n,B,m);
	int ires = Intersection(A,n,B,m);
	cout<<"\nNo of Elements in Union : "<<res;
	cout<<"\nNo of Elements in Intersection : "<<ires;
	delete[] A;
	delete[] B;
	return 0;
}




