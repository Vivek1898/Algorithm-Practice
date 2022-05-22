// Maximum sum of subarray less than or equal to x 
// Easy Accuracy: 36.65% Submissions: 2726 Points: 2
// Given an array arr[] of integers of size N and a number X, the task is to find the sum of subarray having maximum sum less than or equal to the given value of X.

// Example 1:

// Input: N = 5, X = 11
// arr[] = {1, 2, 3, 4, 5} 
// Output:  10
// Explanation: Subarray having maximum 
// sum is {1, 2, 3, 4}.
 
// Example 2:

// Input: N = 5, X = 7
// arr[] = {2, 4, 6, 8, 10} 
// Output:  6
// Explanation: Subarray having maximum 
// sum is {2, 4} or {6}.
 

// Your Task:
// This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function calculateMaxSumLength() that takes array arr, integer N, and integer X as parameters and returns maximum sum of any subarray that is less than or equal to x.

 

// Expected Time Complexity: O(N). 
// Expected Auxiliary Space: O(1).

 

// Constraints:
// 1 ≤ N ≤ 106


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	long findMaxSubarraySum(long long nums[], int n, long long target)
	{
	    long long slow=0,sum=0,mAXLen=0;
        
        for(long fast=0;fast<n;fast++){
            sum+=nums[fast];
            
            while(sum>target){
                //Exclude
                sum-=nums[slow];
                slow++;
            }
               mAXLen=max(mAXLen,sum);
        }
     
    
        return mAXLen;
	}  

		 

};
	  



// { Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	 int n;
        cin>>n;
        
        long long a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        long long sum;
        cin >> sum;
        

        Solution ob;
		cout << ob.findMaxSubarraySum(a, n, sum);
        
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends