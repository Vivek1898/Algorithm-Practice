//BOX CHHOSES

import java.io.*;
import java.util.*;

public class Main {

    public static void queensCombinations(int qpsf, int tq, int row, int col, String mat){
        //Base Case
        if(row ==tq){
            if(qpsf==tq){
                System.out.println(mat);
               
            }
             return;
        }
        if(qpsf>tq){
            return;
        }
        
        
        
        if(col==tq-1){
            //Agli row ke phle elememt pe jana hai
            //Row -->row +1
            //Col agli row pe 0 hoga
            //Yes
            queensCombinations(qpsf+1,tq,row+1,0,mat+'q'+'\n');
           //No
           //Jab h 2nd row pw start me hai
            queensCombinations(qpsf,tq,row+1,0,mat+'-'+'\n');
        }else{
            //Queen daalo ya mt daalo isliye 2
            //Agar wo last element nahi hai.
            queensCombinations(qpsf+1,tq,row,col+1,mat+'q');
            
            //no queen mt daalo
              queensCombinations(qpsf,tq,row,col+1,mat+'-');
        }
        
        
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        
        queensCombinations(0, n, 0, 0, "");
    }
}