//7.PERMUTATION 

import java.io.*;
import java.util.*;

public class Main {

  public static void permutations(int CurrentBox, int n,int kitems,boolean[] itemPlaced,String Boxes,int itemPlacedCount){
      //Base Case 
      //Check for length of item placed so we can Print
      if(CurrentBox == n){
          if(itemPlacedCount == kitems){
              System.out.println(Boxes);
              
          }
          return;
      }
    // Place ONly UNplaced Item
    for(int i=0;i<kitems;i++){
        if(itemPlaced[i]==false){
            itemPlaced[i]=true;
            //Place the current item i in Boxes array 0,1,2
            permutations(CurrentBox+1,n,kitems,itemPlaced,Boxes+(i+1),itemPlacedCount+1);
            //BackTrack
            itemPlaced[i]=false;
        }
    }
    
    // CurrentBox-> Do not place any item
    //Else Place O Or _ as per given in question
     permutations(CurrentBox+1,n,kitems,itemPlaced,Boxes+0,itemPlacedCount);
    
    
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    int k = Integer.parseInt(br.readLine());
    //Item is visited or not
   boolean[] itemPlaced = new boolean[k];
   //Making String of total boxes and place 0 in it
   String boxes="";
permutations(0,n,k,itemPlaced,boxes,0);
  }

}