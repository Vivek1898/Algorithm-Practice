// https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1#
// Smallest distinct window 
// Medium Accuracy: 50.29% Submissions: 21910 Points: 4
// Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
// For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

 

// Example 1:

// Input : "AABBBCBBAC"
// Output : 3
// Explanation : Sub-string -> "BAC"
// Example 2:
// Input : "aaab"
// Output : 2
// Explanation : Sub-string -> "ab"
 
// Example 3:
// Input : "GEEKSGEEKSFOR"
// Output : 8
// Explanation : Sub-string -> "GEEKSFOR"
 


// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function findSubString() which takes the string  S as input and returns the length of the smallest such window of the string.


// Expected Time Complexity: O(256.N)
// Expected Auxiliary Space: O(256)


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        
         int n = str.size();
        
        int uniq =  unordered_set<char>(str.begin(), str.end()).size();

        unordered_map<char, int> hm;
        
        int i = 0, j = 0;
        int ans = INT_MAX, potentialAns = INT_MAX;
       
        while(j < n){
            
            //Acquire values upto unique character with first pointer
            hm[str[j++]]++;
         // Release from 2nd ponter
            while(hm.size() == uniq){
                // Valiad length between two pointers
                potentialAns = j-i;
                ans = min(ans, potentialAns);
                //Start removal process with 2nd pointer and update 2nd pointer
                hm[str[i]]--;
                if(hm[str[i]]==0) 
                	hm.erase(str[i]);
                i++;
            }
        }
       
       return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends
 