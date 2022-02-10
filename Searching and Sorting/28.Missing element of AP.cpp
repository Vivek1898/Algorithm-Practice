// { Driver Code Starts
//Initiaal template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMissing(int arr[], int n) {
        
        int commondiff = (arr[n-1]-arr[0])/n;
        int left=0, right=n-1,ans=0;
        while(left <= right) {
         int mid = left+(right-left)/2;
         int actual=arr[mid];
         int expv=arr[0] + commondiff*mid;
         if(actual==expv) left=mid+1;
         else{
             ans=expv;
             right=mid-1;
         }
          
        }
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMissing(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends