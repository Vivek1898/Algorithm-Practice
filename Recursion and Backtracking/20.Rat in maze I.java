// Initial Template for Java

import java.util.*;
class Rat {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[][] a = new int[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) a[i][j] = sc.nextInt();

            Solution obj = new Solution();
            ArrayList<String> res = obj.findPath(a, n);
            Collections.sort(res);
            if (res.size() > 0) {
                for (int i = 0; i < res.size(); i++)
                    System.out.print(res.get(i) + " ");
                System.out.println();
            } else {
                System.out.println(-1);
            }
        }
    }
}
// } Driver Code Ends


// User function Template for Java

// m is the given matrix and n is the order of matrix
class Solution {
static ArrayList<String> res;
    
    static int[] x = {+1, 0, 0, -1};
    static int[] y = {0, -1, +1, 0};
    static Character[] ch = {'D', 'L', 'R', 'U'};
    
    public static void findPath(int r, int c, int[][] mat, String pathSofar){
        if(r < 0 || r >= mat.length || c < 0 || c >= mat[0].length){
            // our][c] == 0 || mat[r][c] == -1){t of matrix negative base case
            return;
        }
        
        if(mat[r][c] == 0 || mat[r][c] == -1){
            // blockage node || visited cell (loop or cycle)
            return;
        }
        
        if(r == mat.length - 1 && c == mat[0].length - 1){
            // Positive Base Case
            res.add(pathSofar);
            return;
        }
        
        mat[r][c] = -1;
        for(int i=0; i<4; i++){
            findPath(r + x[i], c + y[i], mat, pathSofar + ch[i]);
        }
        mat[r][c] = 1;
    }
    
    
    
    
    public static ArrayList<String> findPath(int[][] mat, int n) {
        res = new ArrayList<>();
        findPath(0, 0, mat, "");
        return res;
    }
}