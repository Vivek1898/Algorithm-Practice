class Solution {
    
    //Item on Level
    List<List<Integer>>res;
    public void combination(List<Integer> ans,HashMap<Integer,Integer> freq, 
                            ArrayList<Integer>uniqueCoins,int crntCoin,int target){
        //+ve base case
        if(target==0){
            res.add(new ArrayList<>(ans));
            return;
        }
        
        if(crntCoin==uniqueCoins.size()){
            return;
        }
        
        int val=uniqueCoins.get(crntCoin);
        
       
        for(int i=0;i<=freq.get(val);i++){
            //Handle -ve indexing
           
                if(target- i * val >= 0){
                for(int j=1;j<=i;j++){
                    ans.add(val);
                }

                  combination(ans,freq,uniqueCoins,crntCoin+1,target - i * val);
                //back track
               
                   for(int j=1;j<=i;j++){
                    ans.remove(ans.size()-1);
                }
        }
        }
        
    }
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        
        
        ArrayList<Integer>uniqueCoins=new ArrayList<>();
        HashMap<Integer,Integer> freq=new HashMap<>();
            
            for(int val:candidates){
                if(freq.containsKey(val)==false){
                    freq.put(val,1);
                    uniqueCoins.add(val);
                }else{
                     freq.put(val,freq.get(val)+1);
                }
               
            }
        res=new ArrayList<>();
        combination(new ArrayList<>(),freq,uniqueCoins,0,target);
        return res;
        
        
    }
}