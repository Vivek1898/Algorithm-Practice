// 1248. Count Number of Nice Subarrays
// Medium

// 1737

// 43

// Add to List

// Share
// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

 

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
// Example 2:

// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There is no odd numbers in the array.
// Example 3:

// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16
 

// Constraints:

// 1 <= nums.length <= 50000
// 1 <= nums[i] <= 10^5
// 1 <= k <= nums.length


class Solution {
public:
    long long helper(vector<int>& nums, int k){
         long long left=0,right=0;
         long long res=0,odd=0;
        for(right=0;right<nums.size();right++){
            if(nums[right]%2==1) odd++;
            if(odd<=k){
                res+=right-left+1;
                continue;
            }
            while(left<=right and odd>k){
                 if(nums[left]%2==1){
                     left++;
                     odd--;
                     res+=right-left+1;
                     break;
                 }
                left++;
            }
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return helper(nums,k)-helper(nums,k-1);
    }
};