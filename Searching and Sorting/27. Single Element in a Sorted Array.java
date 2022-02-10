class Solution {
    public int singleNonDuplicate(int[] nums) {
        int low=0;
        int high=nums.length-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int lval=(mid-1>=0)?nums[mid-1]:-1;
             int rval=(mid+1<nums.length)?nums[mid+1]:-1;
            if(nums[mid]!=lval && nums[mid]!=rval){
                return nums[mid];
            }
            
            if(nums[mid]==lval){
                int lcount=mid-low-1;
                if(lcount%2==1){
                    high=mid-2;
                }else{
                    low=mid+1;
                }
            }else{
                 int lcount=mid-low;
                if(lcount%2==1){
                    high=mid-1;
                }else{
                    low=mid+2;
                }
            }
        }
        return -1;
        
    }
}