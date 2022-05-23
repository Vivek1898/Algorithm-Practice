// Longest K unique characters substring
// Easy Accuracy: 49.84% Submissions: 27922 Points: 2
// Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

// Example 1:

// Input:
// S = "aabacbebebe", K = 3
// Output: 7
// Explanation: "cbebebe" is the longest
// substring with K distinct characters.
// Example 2:

// Input:
// S = "aaaa", K = 2
// Output: -1
// Explanation: There's no substring with K
// distinct characters.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestKSubstr() which takes the string S and an integer K as input and returns the length of the longest substring with exactly K distinct characters. If there is no substring with exactly K distinct characters then return -1.

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(1).

// { Driver Code Starts
// Initial template for C++
// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1#
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        // your code here

        unordered_map<char, int> m;
        int i = 0, j = 0;
        int ans = -1;
        while (j < s.size())
        {
            m[s[j]]++;
            // Acquire
            if (m.size() < k)
            {
                j++;
            }
            else if (m.size() == k)
            {
                ans = max(ans, j - i + 1);
                j++;
            }
            else if (m.size() > k)
            {
                // Release
                while (m.size() > k)
                {
                    m[s[i]]--;
                    if (m[s[i]] == 0)
                    {
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
// } Driver Code Ends