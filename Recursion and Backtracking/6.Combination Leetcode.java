class Solution {
   public void combine(List<List<Integer>> combinations, 
        List<Integer> CurrentCombination, int currentBox, int n, int k){
        if(currentBox == n){
            if(CurrentCombination.size() == k){
                // deep copy
                List<Integer> temp = new ArrayList<>(CurrentCombination);
                combinations.add(temp);
            }
            return;
        }
        
        // options -> current Box -> item should be placed or not
        
        // yes
        CurrentCombination.add(currentBox + 1);
        combine(combinations, CurrentCombination, currentBox + 1, n, k);
        CurrentCombination.remove(CurrentCombination.size() - 1);
        
        // no
       //item no+1 b/c for last result we have to get perfect combination
        combine(combinations, CurrentCombination, currentBox + 1, n, k);
    }
    
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> combinations = new ArrayList<>();
        List<Integer> combination = new ArrayList<>();
        //We start from Box 0 and then start adding for two cases
        combine(combinations, combination, 0, n, k);
        return combinations;
    }
}






























