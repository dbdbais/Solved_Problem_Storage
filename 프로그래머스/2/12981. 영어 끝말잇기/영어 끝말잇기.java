import java.util.*;
class Solution {
    HashSet<String> set;
    int cnt;
    public int[] solution(int n, String[] words) {
        int[] answer = new int[2];
        boolean found = false;
        set = new HashSet<>();
        
        String prev = words[0];
        set.add(prev);
        cnt++;
        for(int i=1;i<words.length;i++){
            String word = words[i];
            // i번째 해당 단어
            System.out.println(prev+":"+word+":"+cnt);
            
            
            char wordFirst = word.charAt(0);
            char prevWordLast = prev.charAt(prev.length()-1);
            if(set.contains(word) || wordFirst != prevWordLast){
                found = true;
                System.out.println("DONE");
                answer[0] = (cnt%n)+1;
                answer[1] = (cnt/n)+1;
                break;
            }
            else{
                set.add(word);
            }
            prev = word;
            cnt++;
            
            
        }
        
        if (!found){
            answer[0] = 0;
            answer[1] = 0;
        }
        
        

        return answer;
    }
}