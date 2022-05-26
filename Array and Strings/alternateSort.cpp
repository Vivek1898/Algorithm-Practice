// Given an array arr[] of N distinct integers, output the array in such a way that the first element is first maximum and the second element is the first minimum, and so on.
 

// Example 1:

// Input: N = 7, arr[] = {7, 1, 2, 3, 4, 
//                                 5, 6}
// Output: 7 1 6 2 5 3 4
// Explanation:The first element is first 
// maximum and second element is first 
// minimum and so on.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	vector<int> alternateSort(int arr[], int N)
	{
	   sort(arr,arr+N);
   int start=0;
   int end=N-1;
   vector<int>v;
   while(start<end){
       v.push_back(arr[end--]);
       v.push_back(arr[start++]);
   }
   // if the element remains in array
   if(start==end)
    v.push_back(arr[end--]);
   return v;
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
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
       

        Solution ob;
        vector<int> ans = ob.alternateSort(a, n);
        for(auto i:ans)
        	cout << i << " ";
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends