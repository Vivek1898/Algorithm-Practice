public class Solution {
    /**
    Input: s = "code"
    Output: False
    Explanation: 
     No solution
     * @param s: the given string
     * @return: if a permutation of the string could form a palindrome
     */
    public boolean canPermutePalindrome(String s) {
        // write your code here
        HashMap<Character,Integer> freq=new HashMap<>();
        //Frequency Table
        for(int i=0;i<s.length();i++){
            if(freq.containsKey(s.charAt(i))==false){
                freq.put(s.charAt(i),1);
            }else{
              freq.put(s.charAt(i),freq.get(s.charAt(i))+1);  
            }
        }
        int oddCount=0;
        for(Character c:freq.keySet()){
            if(freq.get(c)%2==1){
                oddCount++;
            }
        }
       if(oddCount>1) return false;
       return true;

    }
}