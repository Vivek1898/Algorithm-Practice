class Solution {
    //ITEM ON LEVEL
    List<List<Integer>>ans = new ArrayList<>();
    public void subset(int crntItem, ArrayList <Integer> uniq, HashMap<Integer,Integer> freq,List<Integer>res){
        //Base 
        if(crntItem==uniq.size()){
            ans.add(new ArrayList<>(res));
            return;
            
        }
            //Get from uniq and add till frquency
        subset(crntItem+1,uniq,freq,res); //no
        int val=uniq.get(crntItem);
        for(int i=0;i<freq.get(val);i++){
            res.add(val);
            //YES
            subset(crntItem+1,uniq,freq,res);
            
        }
            for(int i=0;i<freq.get(val);i++){
            res.remove(res.size()-1);
            }
    }
  
    
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        ArrayList <Integer> uniq=new ArrayList<>();
        HashMap<Integer,Integer> freq=new HashMap<>();
        
        for(int val:nums){
            if(freq.containsKey(val)==true){
                
                freq.put(val,freq.get(val)+1);
                
            }else{
                freq.put(val,1);
                uniq.add(val);
            }
        }
           subset(0,uniq,freq,new ArrayList<>());
        return ans;
        
    }
}