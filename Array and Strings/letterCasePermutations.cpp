// 784. Letter Case Permutation
// Medium

// 3325

// 144

// Add to List

// Share
// Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

// Return a list of all possible strings we could create. Return the output in any order.

 

// Example 1:

// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]
// Example 2:

// Input: s = "3z4"
// Output: ["3z4","3Z4"]


class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> perm;
        if(s==""){
            return perm;
        }
        
        perm.push_back(s);
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])){
                int n=perm.size();
                for(int j=0;j<n;j++){
                    vector<char>chars(perm[j].begin(),perm[j].end());
                    if(isupper(chars[i])){
                        chars[i]=tolower(chars[i]);
                    }else{
                         chars[i]=toupper(chars[i]);
                    }
                            perm.push_back(string(chars.begin(),chars.end()));

                }
            }
        }
        return perm;
    }
};