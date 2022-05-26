// Given an array nums of positive integers of size N. Find all distinct digits present in nums.
 

// Example 1:

// Input: nums = [131, 11, 48]
// Output: 1 3 4 8
// Explanation: 1, 3, 4, and 8 are only distinct
// digits that can be extracted from the numbers
// of the array.
// Example 2:

// Input: nums = [111, 222, 333, 4444, 666]
// Output: 1 2 3 4 6
// Explanation: 1, 2, 3, 4, and 6 are only distinct
// digits that can be extracted from the numbers
// of the array.
 

// Your Task: 
// You don't need to read or print anything. Your task is to complete the function common_digits() which takes nums as input parameter and returns a list of digits which can be extracted from the given array in ascending order.

// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
   	vector<int>  common_digits(vector<int>nums){
   	    // Code here
   	    // Code here
   	    map<int,int> mp;
   	    for(int i=0;i<nums.size();i++){
   	        while(nums[i]>0){
   	            mp[nums[i]%10]++;
   	            nums[i]/=10;
   	        }
   	        
   	    }
   	    vector<int> v;
   	    for(auto it:mp){
   	        v.push_back(it.first);
   	    }
   	    return v;
   	}    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < nums.size(); i++)cin >> nums[i];
		Solution ob;
		vector<int> ans = ob.common_digits(nums);
		for(auto i: ans)
			cout << i << " ";
		cout << "\n";
	}  
	return 0;
}  // } Driver Code Ends