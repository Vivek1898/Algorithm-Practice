




class Solution {
    List<List<Integer>>res;
    
    public static void swap(int []nums,int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    
   public void permutations(int CurrentBox,int[]nums){
      //Base Case 
      //Check for length of item placed so we can Print
       if(CurrentBox==nums.length){
           List<Integer>copy=new ArrayList<>();
            for(int i=0;i<nums.length;i++){
                copy.add(nums[i]);
            }
           res.add(copy);
           return;
       }  
      
    // Place ONly UNplaced Item
    for(int i=CurrentBox;i<nums.length;i++){
     
            // Swap Current Box (Standing Index  ) with current Element in nums[]
            swap(nums,CurrentBox,i);
            permutations(CurrentBox+1,nums);
            //BACTRACK WAPAS AATE TIME
             swap(nums,CurrentBox,i);
          
        }  
  }
    public List<List<Integer>> permute(int[] nums) {
        this.res=new ArrayList<>();
    
     permutations(0,nums);
        return res;
    }
}
