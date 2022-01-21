class Solution {
    List<String> res;
    
    String[] keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    public void letterCombinations(int idx, String input, String output){
        //Avoid empty
        if(idx == input.length()){
            if(output.length() > 0){
                res.add(output);
            }
            return;
        }
        //Get Character at that index
        char digit = input.charAt(idx);
        //Convert to integer then add to ress one by one
        for(char letter: keypad[digit - '0'].toCharArray()){
            letterCombinations(idx + 1, input, output + letter);
        }
    }
    
    public List<String> letterCombinations(String digits) {
        res = new ArrayList<>();
        letterCombinations(0, digits, "");
        return res;
    }
}