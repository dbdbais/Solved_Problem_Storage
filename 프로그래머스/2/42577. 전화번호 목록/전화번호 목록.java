import java.util.*;
class Solution {
    public ArrayList<String> lst;
    public HashSet<String> set = new HashSet();
    public StringBuilder sb;
    
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        lst = new ArrayList<>(Arrays.asList(phone_book));
        Collections.sort(lst,new Comparator<String>(){
            public int compare(String s1, String s2){
                if(s1.length() == s2.length()){
                    return s1.compareTo(s2);
                }
                else{
                    return Integer.compare(s1.length(),s2.length());
                }
            }
        });
        
        for(String s : lst){
            for(int i=0;i<=s.length();i++){
                String e = s.substring(0,i);
                if(set.contains(e)){
                    //System.out.println(e);
                    answer = false;
                    break;
                }
            }
            set.add(s);
        }
        
        
        
        
        return answer;
    }
}