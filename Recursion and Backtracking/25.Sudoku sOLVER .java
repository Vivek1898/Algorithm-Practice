/* Input: board = [["5","3",".",".","7",".",".",".","."],
                ["6",".",".","1","9","5",".",".","."],
                [".","9","8",".",".",".",".","6","."],
                ["8",".",".",".","6",".",".",".","3"],
                ["4",".",".","8",".","3",".",".","1"],
                ["7",".",".",".","2",".",".",".","6"],
                [".","6",".",".",".",".","2","8","."],
                [".",".",".","4","1","9",".",".","5"],
                [".",".",".",".","8",".",".","7","9"]]

Output: [["5","3","4","6","7","8","9","1","2"],
        ["6","7","2","1","9","5","3","4","8"],
        ["1","9","8","3","4","2","5","6","7"],
        ["8","5","9","7","6","1","4","2","3"],
        ["4","2","6","8","5","3","7","9","1"],
        ["7","1","3","9","2","4","8","5","6"],
        ["9","6","1","5","3","7","2","8","4"],
        ["2","8","7","4","1","9","6","3","5"],
        ["3","4","5","2","8","6","1","7","9"]]   */
        class Solution {
    
    public boolean isSudokuValid(char[][] board, int row, int col, char ch){
        // row element
        for(int j=0; j<9; j++){
            if(board[row][j] == ch){
                return false;
            }
        }
        
        // column element
        for(int i=0; i<9; i++){
            if(board[i][col] == ch){
                return false;
            }
        }
        
        int crow = (row / 3) * 3;
        int ccol = (col / 3) * 3;
        
        // submatrix element
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i + crow][j + ccol] == ch){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    public boolean solveSudoku(char[][] board, int row, int col){
        if(row == 9) return true; 
        // positive base case -> all boxes are filled
        
        int nextRow = (col == 8) ? row + 1 : row;
        int nextCol = (col == 8) ? 0 : col + 1;
        
        if(board[row][col] != '.'){
            // already filled
            boolean res = solveSudoku(board, nextRow, nextCol);
            if(res == true) return true;
            
        } else {
            
            // empty fill -> explore all valid options
            for(int i=1; i<=9; i++){
                if(isSudokuValid(board, row, col, (char)(i + '0')) == true){
                    board[row][col] = (char)(i + '0');
                    boolean res = solveSudoku(board, nextRow, nextCol);
                    if(res == true) return true;
                    
                    board[row][col] = '.';
                }
            }
            
        }
        
        return false; // sudoku is not solvable
    }
    
    public void solveSudoku(char[][] board) {
        solveSudoku(board, 0, 0);
    }
}

//VALIAD SUDOKU

class Solution {
    public boolean isSudokuValid(char[][] board, int row, int col, char ch){
        // row element
        for(int j=0; j<9; j++){
            if(board[row][j] == ch && j != col){
                return false;
            }
        }
        
        // column element
        for(int i=0; i<9; i++){
            if(board[i][col] == ch && i != row){
                return false;
            }
        }
        
        int crow = (row / 3) * 3;
        int ccol = (col / 3) * 3;
        
        // submatrix element
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i + crow][j + ccol] == ch 
                    && i + crow != row && j + ccol != col){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    public boolean solveSudoku(char[][] board, int row, int col){
        if(row == 9) return true; 
        // positive base case -> all boxes are filled
        
        int nextRow = (col == 8) ? row + 1 : row;
        int nextCol = (col == 8) ? 0 : col + 1;
        
        if(board[row][col] != '.'){
            // already filled valiad cells h ya nahi
            
            if(isSudokuValid(board, row, col, board[row][col]) == false) 
                return false;
        } 
        
        return solveSudoku(board, nextRow, nextCol); // sudoku is not solvable
    }

    public boolean isValidSudoku(char[][] board) {
        return solveSudoku(board, 0, 0);
    }
}


//MAX SCORE

class Solution {
    
    public int maxScore(int idx, String[] words, int[] freq, int[] score){
        if(idx == words.length) return 0;
        
        // yes
        int currScore = 0;
        boolean flag = true;
        for(char ch : words[idx].toCharArray()){
            //If frequency over so bactrack 
            freq[ch - 'a']--;
            //If freq becomes -ve
            if(freq[ch - 'a'] < 0){
                flag=false;
               
            }
            //Us character ka score uthao
            currScore += score[ch - 'a'];
        }
        
        //agar us word ko le sakte h to le lia
        if(flag == true){
            currScore += maxScore(idx + 1, words, freq, score);    
            
            }else{
            //nahi to score 0   
           currScore = 0;
        }
        // backtrack
         for(char ch :words[idx].toCharArray()){
           
               freq[ch - 'a']++;
           }     
        // no
        return Math.max(currScore, maxScore(idx + 1, words, freq, score));
    }
    
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        int[] freq = new int[26];
        for(char ch: letters) freq[ch - 'a']++;
        return maxScore(0, words, freq, score);
    }
}
