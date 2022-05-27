// 78. Subsets
// Medium

// 10090

// 157

// Add to List

// Share
// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>powerset;
        powerset.push_back({});
        for(auto currentNumber:nums){
            int n=powerset.size();
            for(int i=0;i<n;i++){
                  vector<int>copy(powerset[i]);
                    copy.push_back(currentNumber);
                        powerset.push_back(copy);
            }
            
        }
        return powerset;
        
    }
};