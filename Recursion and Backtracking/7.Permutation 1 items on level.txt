//8.PERMUTATION 2

import java.io.*;
import java.util.*;

public class Main {

  public static void permutations(int CurrentItem,int n,int k ,int[] boxes){
  if(CurrentItem==k){
      for(int val:boxes) System.out.print(val);
      System.out.println();
      return;
  }
  
    // item have To CHOOSE WHICH BOX TO SELECT
   //EXPLORE EACH BOC MARK AND BACKTRACK
   for(int i=0;i<n;i++){
      if(boxes[i]==0){
          //PLace Current item
        boxes[i]=CurrentItem+1;
        permutations(CurrentItem+1,n,k,boxes);
        boxes[i]=0;
      }
   }
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n= Integer.parseInt(br.readLine());
    int k = Integer.parseInt(br.readLine());
    permutations(0,n,k,new int[n]);
  }

}