    public void permute2(HashMap<Integer,Integer> lastidx,int[] nums,int CurrentItem,List<Integer>ans){
        
        if(CurrentItem==nums.length){
             //Deep copy 
            List<Integer>copy=new ArrayList(ans);
             res.add(copy);
            return;
        }
        
        int st=lastidx.get(nums[CurrentItem]);
        for (int i=st+1;i<ans.size();i++){
            //Check for already Placed for next item
            if(ans.get(i)==null){
               ans.set(i,nums[CurrentItem]) ;
                //Update last Index for next itr
                lastidx.put(nums[CurrentItem],i);
               permute2(lastidx,nums,CurrentItem+1,ans); 
                //Backtrack
                //Set previous state
                lastidx.put(nums[CurrentItem],st);
                ans.set(i,null) ;
                
            }
            
        }
        
        
    }
    public List<List<Integer>> permuteUnique(int[] nums) {
        
        HashMap<Integer,Integer> lastidx=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            lastidx.put(nums[i],-1);
            
        }
       List<Integer> ans= new ArrayList<>();
         for(int i=0;i<nums.length;i++){
            ans.add(null);
            
        }
        
         res= new ArrayList<>();
        permute2(lastidx,nums,0,ans);
        return res;
    }
}