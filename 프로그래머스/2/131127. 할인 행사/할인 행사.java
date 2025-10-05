import java.util.*; 
class Solution {
    /*
    xyz 마트는 일정한 금액을 지불하면 10일 동안 회원자격을 부여, XYZ마트에서는 회원을 대상으로 매일 한 가지 제품을 할인하는 행사를 한다. 10일 연속으로 일치 할 경우 회원가입을 한다.
    
    바나나 3개, 사과 2개, 쌀 2개
    */
    
    HashMap<String,Integer> map;
    String [] gwant,gdiscount;
    int [] gnumber;
    int dn;
    void init(){
        map = new HashMap<>();
        for(int i=0;i<gwant.length;i++){
            String w = gwant[i];
            int num = gnumber[i];
            map.put(w,num);
        }
        // for(String k : map.keySet()){
        //     System.out.println(k+":"+map.get(k));
        // }
    }
    
    boolean check(int idx,int len){
        //System.out.println(idx);
        boolean ret = true;
        
        HashMap<String,Integer> tmp = new HashMap<>();
        
        for(int i = idx; i< idx+len;i++){
            String elem = gdiscount[i];
            if(tmp.containsKey(elem)){
                int val = tmp.get(elem) + 1;
                tmp.put(elem,val);
            }
            else{
                tmp.put(elem,1);
            }
        }
        
        for(String k : map.keySet()){
            if(tmp.containsKey(k)){
                if(tmp.get(k) < map.get(k)){
                    ret = false;
                    break;
                }
            }
            else{
                ret = false;
                break;
            }
        }
        
        return ret;
        
    }
    
    
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        gwant = want;
        gnumber = number;
        gdiscount = discount;
        dn = discount.length;
        init();
        
        
        for(int i=0;i<=dn-10;i++){
            if(check(i,10)){
                answer++;
            }
        }
        
        return answer;
    }
}