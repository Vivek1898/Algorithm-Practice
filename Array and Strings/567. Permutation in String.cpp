// 567. Permutation in String
// Medium

// 5896

// 174

// Add to List

// Share
// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false

// Constraints:

// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int window = s1.size(), lenS2 = s2.size();
        if (window > lenS2)
            return false;

        vector<int> countS1(26, 0), countS2(26, 0);
        for (int i = 0; i < window; ++i)
        {
            countS1[s1[i] - 'a']++;
            countS2[s2[i] - 'a']++;
        }
        if (countS1 == countS2)
            return true;
        for (int i = window; i < lenS2; ++i)
        {
            countS2[s2[i] - 'a']++;
            // exclude
            countS2[s2[i - window] - 'a']--;
            if (countS1 == countS2)
                return true;
        }
        return false;
    }
};