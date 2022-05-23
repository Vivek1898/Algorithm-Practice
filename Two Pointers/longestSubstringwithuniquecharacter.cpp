// 3. Longest Substring Without Repeating Characters
// Medium

// 23760

// 1057

// Add to List

// Share
// Given a string s, find the length of the longest substring without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          map<char,int> m;
        
        int ans=0;
        
        for(int ahead=0,back=0;ahead<s.size();){
            if(!m[s[ahead]]){
                m[s[ahead]]++;
                ahead++;
                ans=max(ans,ahead-back);
            }
            else{
                m[s[back]]--;
                back++;
            }
        }
        return ans;
    }
};