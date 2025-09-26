import java.util.*;

class Solution {
    public String solution(String s) {
		char temp = ' ';
		boolean isCap = true;
		StringBuffer sb = new StringBuffer();
		
		for(int i = 0 ; i < s.length() ; i++ ) {
			temp = s.charAt(i);
			
			if( isCap ) {
				sb.append(Character.toUpperCase(temp));
				isCap = false;
			}else {
				sb.append(Character.toLowerCase(temp));
			}
			
			if( temp == ' ') {
				isCap = true;
			}
		}
		
		return sb.toString();
	}
}