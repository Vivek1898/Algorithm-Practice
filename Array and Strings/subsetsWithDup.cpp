// 90. Subsets II
// Medium

// 5143

// 154

// Add to List

// Share
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<vector<int>>powerset;
        powerset.push_back({});
        int startIdx=0,endIdx=0;
        for(int i=0;i<nums.size();i++){
            startIdx=0;
            
            if(i>0 and nums[i]==nums[i-1]){
                startIdx=endIdx+1;
            }
            
            endIdx=powerset.size()-1;
            for(int j=startIdx;j<=endIdx;j++){
                  vector<int>copy(powerset[j]);
                    copy.push_back(nums[i]);
                        powerset.push_back(copy);
            }
            
        }
        return powerset;
    }
};