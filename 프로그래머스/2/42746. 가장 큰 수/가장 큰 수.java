import java.util.*;
class Solution {
    ArrayList<String> lst;
    public String solution(int[] numbers) {
        String answer = "";
        lst = new ArrayList<>();
        
        for(int elem : numbers){
            lst.add(Integer.toString(elem));
        }
        Collections.sort(lst,new Comparator<String>(){
           public int compare(String s1, String s2){
               return (s2+s1).compareTo(s1+s2);
           } 
        });
        
        StringBuilder sb = new StringBuilder();
        
        for(String st : lst){
            sb.append(st);
        }
        
        answer = sb.toString();
        
        if (answer.charAt(0) == '0') answer = "0";
        
        
        return answer;
    }
}