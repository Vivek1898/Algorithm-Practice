class Solution {
    
    //Item on Level infinite
    List<List<Integer>>res;
    public void combination(List<Integer> ans,int[]uniqueCoins, int crntCoin,int target){
        //+ve base case
        if(target==0){
            res.add(new ArrayList<>(ans));
            return;
        }
        
        if(crntCoin==uniqueCoins.length){
            return;
        }
        
        int val=uniqueCoins[crntCoin];
  
        for(int i=0;target- i * val >= 0;i++){
           
                for(int j=1;j<=i;j++){
                    ans.add(val);
                }

                  combination(ans,uniqueCoins,crntCoin+1,target - i * val);
                //back track
                
                   for(int j=1;j<=i;j++){
                    ans.remove(ans.size()-1);
                }
        
        }
        
    }
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        

        res=new ArrayList<>();
        combination(new ArrayList<>(),candidates,0,target);
        return res;
        
        
    }
}