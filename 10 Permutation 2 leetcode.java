class Solution {
    List<List<Integer>> res;
    public void permute(HashMap<Integer,Integer>freq,int[] nums,int CurrentBox,List<Integer>ans){
        if(CurrentBox== nums.length){
            //Deep copy 
            List<Integer>copy=new ArrayList(ans);
             res.add(copy);
            return;
        }
        //Loop on KeySet
        //Corresponding value ---to key
        for(Integer key: freq.keySet()){
            //Old freq
            int val=freq.get(key);
             //Check for every character
            if(val>0){
                //DECREASE Current Frequency
                //Becaue that word is used so we have to
                //Decrease the freq of that word
                freq.put(key,val-1);
                ans.add(key);
                permute(freq,nums,CurrentBox+1,ans);
                //BACTRACK MAKE SAME STATE
                ans.remove(ans.size()-1);
                freq.put(key,val);
            }
        }
        
        
        
        
        
    }
    public List<List<Integer>> permuteUnique(int[] nums) {
        
        HashMap<Integer,Integer> freq=new HashMap<>();
        //MAINTAIN FREQ IN HASHMAPS
        //To count Unique elemennts
        for(int i=0;i<nums.length;i++){
            if(freq.containsKey(nums[i])){
                int val=freq.get(nums[i]);
                freq.put(nums[i],val+1);
            }else{
                freq.put(nums[i],1);
            }
        }
        res= new ArrayList<>();
        permute(freq,nums,0,new ArrayList<>());
        return res;
    }
}