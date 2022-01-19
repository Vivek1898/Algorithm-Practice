import java.io.*;
import java.util.*;

public class Main {
    public static void combination(ArrayList<Character> chs,int lastidx,String res,int k){
        
            if(res.length()==k){
                System.out.println(res);
            }
      
        
        //start from last idx+1 to avoid permmutation 
        for(int i=lastidx+1;i<chs.size();i++){
            combination(chs,i,res+chs.get(i),k);
        }
        
    }

  public static void main(String[] args){
      Scanner scn=new Scanner(System.in);
      String str=scn.nextLine();
      int k=scn.nextInt();
      
      HashSet<Character> uniq=new HashSet<>();
       ArrayList<Character>chs=new ArrayList<>();
       
       //MAINTAINIG ORDER
       
      for(int i=0;i<str.length();i++){
          if(uniq.contains(str.charAt(i))==false){
              chs.add(str.charAt(i));
          }
          uniq.add(str.charAt(i));
      }
     
     
      combination(chs,-1,"",k);

  }

}