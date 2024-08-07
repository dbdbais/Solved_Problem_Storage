import java.io.*;
import java.util.*;
class Solution {
  
    public String solution(int[] numbers) {
        String answer = "";
        int n = numbers.length;
        String[] snumbers = new String[n]; 
        
        for(int i=0;i<n;i++){
            snumbers[i] = Integer.toString(numbers[i]);
        }
        
        Arrays.sort(snumbers, new Comparator<String>(){
           public int compare(String s1,String s2){
             return (s2 + s1).compareTo(s1 + s2);
           } 
        });
        
        StringBuilder sb = new StringBuilder();
        
        for(String elem : snumbers){
            sb.append(elem);
        }
        
        answer = sb.toString();
        if(answer.charAt(0) == '0')
            answer = "0";
        return answer;
    }
    
}