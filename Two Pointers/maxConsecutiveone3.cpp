// 1004. Max Consecutive Ones III
// Medium

// 4382

// 58

// Add to List

// Share
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
// 0 <= k <= nums.length



class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int maxLen=0;
        int countZero=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0)countZero++;
            
               while(countZero>k){
                   //EXCLUDE
                 if (nums[left]==0) countZero--;
                   left++;
               }
            maxLen=max(maxLen,right-left+1);
        }
      return maxLen;  
    }
  

                         

                     
};