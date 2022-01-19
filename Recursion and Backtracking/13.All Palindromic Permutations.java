import java.io.*;
import java.util.*;

public class Main {

	public static void generatepw(int currentBox, HashMap<Character, Integer> freq, StringBuilder permutation) {
	    if(currentBox==permutation.length()/2){
	        System.out.println(permutation);
	    }
	    
	    
	    //N and n-1
	    for(Character ch:freq.keySet()){
	        if(freq.get(ch)>0){
	            int oldfreq=freq.get(ch);
	            //Decrease freq for n and n-1
	            freq.put(ch,oldfreq-2);
	            //from start
	            permutation.setCharAt(currentBox,ch);
	            //from end
	            permutation.setCharAt(permutation.length()-1-currentBox,ch);
	            
	            generatepw(currentBox+1,freq,permutation);
	            //Backtrack
	             //from start
	            permutation.setCharAt(currentBox,'0');
	            //from end
	            permutation.setCharAt(permutation.length()-1-currentBox,'0');
	            freq.put(ch,oldfreq);
	            
	            
	        
	    }  
	    }
	  
	    
	    
	    
		
	}

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		
		HashMap<Character, Integer> freq = new HashMap<>();
		for (int i = 0; i < str.length(); i++) {
			char ch = str.charAt(i);
			//CH---GET CH VALUE IF ALRADY PRESENT AND ADD +1
			//IF NO PRESENT 0+1
			freq.put(ch, freq.getOrDefault(ch, 0) + 1);
		}
		Character oddFreqChar='0';
			for (Character ch:freq.keySet()) {
			    if(freq.get(ch)%2==1){
			        //Ignorring 2nd count of odd character if         already odd character prresents
			        if(oddFreqChar!='0'){
			            System.out.println("-1");
			            return;
			        }
			        oddFreqChar=ch;
			    }
			    
			}
		
		StringBuilder permutation= new StringBuilder("");
		//No items placed on box
		for(int i=0;i<str.length();i++){
		    permutation.append("0");
		}
		//If odd freq exxist then put
		if(str.length()%2==1){
		    //place odd in permutation mid
		    permutation.setCharAt(str.length()/2,oddFreqChar);
		    //And Decrease initial values of map b/c odd char placed
		    freq.put(oddFreqChar, freq.getOrDefault(oddFreqChar, 0) + -1);
		}
		//write your code here
		generatepw(0,freq,permutation);
		
	}
	
}