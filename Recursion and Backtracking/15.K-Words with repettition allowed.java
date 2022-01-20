import java.io.*;
import java.util.*;

public class Main {
//with repettition allowed
public static  void combination(int currentChar,String ustr,HashMap<Character,Integer>freq,String res,int k){
    
    if(res.length()==k){
        System.out.println(res);
        return;
    }
    //-ve base case
    if(currentChar==ustr.length()){
        return;
    }
    //GET CURRENT CHAR 
    //TRAVERSE TILL FREQ OF THAT CHARACTER
    //Decide= how many times we have to inert the character
    int val=freq.get(ustr.charAt(currentChar));
    for(int i=val;i>=0;i--){
        
        if(i + res.length()>k){
            continue;
        }
        
    //Now adding i times that char
    //add a 3
    //order a3,a2, --reverse
    //updat ans
    String newRes=res;
    for(int j=1;j<=i;j++){
        newRes+=ustr.charAt(currentChar);
    }
    combination(currentChar+1,ustr,freq,newRes,k);
    
    }
    
}
  
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String str = br.readLine();
    int k = Integer.parseInt(br.readLine());

    HashMap<Character, Integer> unique = new HashMap<>();
    String ustr = "";
    for (char ch : str.toCharArray()) {
      if (unique.containsKey(ch) == false) {
        unique.put(ch, 1);
        ustr += ch;
      } else {
        unique.put(ch, unique.get(ch) + 1);
      }
    }

   combination(0,ustr,unique,"",k);
  }

}