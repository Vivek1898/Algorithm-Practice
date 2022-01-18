class Solution {
    List<List<Integer>>res;
    int[]nums;
    
   public void permutations(int CurrentBox,boolean[] itemPlaced,List<Integer>boxes){
      //Base Case 
      //Check for length of item placed so we can Print
       if(CurrentBox==nums.length){
           List<Integer>copy=new ArrayList<>(boxes);
           res.add(copy);
           return;
       }
    
      
    // Place ONly UNplaced Item
    for(int i=0;i<nums.length;i++){
        if(itemPlaced[i]==false){
            itemPlaced[i]=true;
            boxes.add(nums[i]);
            //Place the current item i in Boxes array 0,1,2
            permutations(CurrentBox+1,itemPlaced,boxes);
            boxes.remove(boxes.size()-1);
            //BackTrack
            itemPlaced[i]=false;
        }
    }
    
  
     
    
  }
    public List<List<Integer>> permute(int[] nums) {
        this.nums=nums;
        this.res=new ArrayList<>();
    
     permutations(0,new boolean[nums.length],new ArrayList<>());
        return res;
    }
}
