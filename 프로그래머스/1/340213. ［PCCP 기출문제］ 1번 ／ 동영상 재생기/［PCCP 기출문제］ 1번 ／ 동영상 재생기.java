import java.util.*;

class Solution {
    /*
    동영상 재생기를 만든다. 10초전으로 이동, 10초 후로 이동, 오프닝 건너 뛰기 3가지 기능을 지원
    
    prev 입력 시 10초 전으로 이동 10초 미만일 시 처음 위치로 0분 0초
    next 입력 시 10초 후로 이동 남은 시간이 10초 미만일 경우 마지막 위치로 이동
    오프닝 건너뛰기 : op_start <= 현재 재생 위치 <= op_end 일 경우 오프닝이 끝나는 위치로
    */
    
    public class Time{
        int mm;
        int ss;
        
        public Time(int mm,int ss){
            this.mm = mm;
            this.ss = ss;
        }
        public Time(Time t){
            this.mm = t.mm;
            this.ss =t.ss;
        }
        
        public String toString(){
            StringBuilder sb =new StringBuilder();
            if(mm < 10){
                sb.append("0"+mm);
            }
            else{
                sb.append(mm);
            }
            sb.append(":");
             if(ss < 10){
                sb.append("0"+ss);
            }
            else{
                sb.append(ss);
            }
            
            
            return sb.toString();
        }
        public void next() {
            ss += 10;
            if (ss >= 60) { // 초가 60 이상이면 분 증가
                ss -= 60;
                mm++;
            }
            if (mm >= 60) { // 60분을 넘으면 마지막 위치로 제한
                mm = 59;
                ss = 59;
            }
        }

        public void prev() {
            ss -= 10;
            if (ss < 0) { // 초가 음수일 경우
                if (mm > 0) {
                    mm--;
                    ss += 60; // 이전 분에서 60초 빌려옴
                } else { 
                    mm = 0; // 0분에서 더 감소하지 않음
                    ss = 0;
                }
            }
        }
        
    }
    
    public boolean gt(Time a, Time b){
        if(a.mm == b.mm){
            return a.ss > b.ss;
        }
        else{
            return a.mm > b.mm;
        }
    }
        public boolean ge(Time a, Time b){
       if (a.mm == b.mm) return a.ss >= b.ss;
        return a.mm > b.mm;
    }
    
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        String [] st = pos.split(":");
        String [] op = op_start.split(":");
        String [] end = op_end.split(":");
        String [] vlen = video_len.split(":");
        
        Time tStart = new Time(0,0);
        
        Time tEnd = new Time(Integer.parseInt(vlen[0]),Integer.parseInt(vlen[1]));
        
        Time tpos = new Time(Integer.parseInt(st[0]),Integer.parseInt(st[1]));
        
        Time oStart = new Time(Integer.parseInt(op[0]),Integer.parseInt(op[1]));
        Time oEnd = new Time(Integer.parseInt(end[0]),Integer.parseInt(end[1]));
        
        
        if(ge(tpos,oStart) && ge(oEnd,tpos)){
            tpos = new Time(oEnd);
        }
        
        for(String s : commands){
           if(s.equals("prev")){
               tpos.prev();
           }
            else{
                tpos.next();
            }
            
            
            // 동영상 끝을 넘을 경우 마지막 위치로 이동
            if (gt(tpos, tEnd)) {
                tpos = new Time(tEnd);
            }
            // 오프닝 범위에 들어가면 오프닝 끝으로 이동
            else if (ge(tpos, oStart) && ge(oEnd, tpos)) {
                tpos = new Time(oEnd);
            }
          
            
            //System.out.println(tpos);
        }
        answer = tpos.toString();
        
        return answer;
    }
}