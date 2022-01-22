class Solution {
    static List<List<String>> res;
    public static boolean isQueenSafe(int r, int c, boolean[][] vis){
        // col (up)
        for(int i=0; i<r; i++){
            if(vis[i][c] == true)
                return false;
        }

        // left diagnol (up)
        int i = r, j = c;
        while(i >= 0 && j >= 0){
            if(vis[i][j] == true){
                return false;
            }
            i--; j--;
        }

        // right diagnol (down)
        i = r; j = c;
        while(j < vis.length && i >= 0){
            if(vis[i][j] == true){
                return false;
            }
            i--; j++;
        }

        return true;
    }

    public static void nqueen(int r, boolean[][] vis) {
        //all queen placed
        if (r == vis.length) {
            List<String> ans = new ArrayList<>();
            for (int i = 0; i < vis.length; i++) {
                String curr = "";
                for (int j = 0; j < vis.length; j++) {
                    if (vis[i][j] == true) {
                        curr = curr + "Q";
                    } else {
                        curr = curr + ".";
                    }
                }
                ans.add(curr);
            }
            res.add(ans);
            return;
        }

        
        for(int c=0; c<vis.length; c++){
            if(isQueenSafe(r, c, vis)){
                vis[r][c] = true; //mark
                nqueen(r + 1, vis);
                vis[r][c] = false;  //Backtrack
            }
        }    
    }

    public List<List<String>> solveNQueens(int n) {
        res = new ArrayList<>();
        boolean[][] vis = new boolean[n][n];
        nqueen(0, vis);
        return res;
        
    }
}

//BRANCH AND BOUND
class Solution {
    static List<List<String>> res;
    
    public static boolean isQueenSafe(int r, int c, boolean[] ld, boolean[] rd, boolean[] col){
        int n = col.length;
        //Check For Indexing 
        return ((ld[r - c + n - 1] == true) || (rd[r + c] == true) || (col[c] == true)) ? false : true;
    }

    public static void nqueen(int r, boolean[][] chess, boolean[] ld, boolean[] rd, boolean[] col) {
        int n = chess.length;
        if (r == n) {
            List<String> ans = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                String curr = "";
                for (int j = 0; j < n; j++) {
                    if (chess[i][j] == true) {
                        curr = curr + "Q";
                    } else {
                        curr = curr + ".";
                    }
                }
                ans.add(curr);
            }
            res.add(ans);
            return;
        }

        
        for(int c=0; c<n; c++){
            if(isQueenSafe(r, c, ld, rd, col)){
                //Mark bounder arrays
                chess[r][c] = ld[r - c + n - 1] = rd[r + c] = col[c] = true;
                nqueen(r + 1, chess, ld, rd, col);
                //backtrack bounded arrays
                chess[r][c] = ld[r - c + n - 1] = rd[r + c] = col[c] = false;
            }
        }    
    }

    public List<List<String>> solveNQueens(int n) {
        res = new ArrayList<>();
        boolean[][] chess = new boolean[n][n];
        boolean[] leftDiagnol = new boolean[2 * n - 1];
        boolean[] rightDiagnol = new boolean[2 * n - 1];
        boolean[] column = new boolean[n];
        
        nqueen(0, chess, leftDiagnol, rightDiagnol, column);
        return res;
        
    }
}