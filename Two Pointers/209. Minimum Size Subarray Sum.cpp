// 209. Minimum Size Subarray Sum
// Medium

// 6574

// 190

// Add to List

// Share
// Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slow=0,sum=0,minLen=INT_MAX;
        
        for(int fast=0;fast<nums.size();fast++){
            sum+=nums[fast];
            
            while(sum>=target){
                minLen=min(minLen,fast-slow+1);
                //Exclude
                sum-=nums[slow];
                slow++;
            }
        }
        //No valiad
        if(minLen == INT_MAX) return 0;
        return minLen;
        
    }
};