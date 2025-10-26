import java.util.*;

class Solution {
    
    class Node{
        String city;
        Node prev, next;
        Node(String city){
            this.city = city;
        }
        void remove(){
            this.prev.next = this.next;
            this.next.prev = this.prev;
        }
        void addLast(Node tail){
            Node prev = tail.prev;
            prev.next = this;
            this.prev = prev;
            this.next = tail;
            tail.prev = this;
        }
    }
    
    
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        if (cacheSize == 0) return cities.length * 5;
        
        Map<String, Node> map = new HashMap<>();
        Node head = new Node(null);
        Node tail = new Node(null);
        
        head.next = tail;
        tail.prev = head;
        
        for (String city : cities){
            city = city.toLowerCase();
            
            if (map.containsKey(city)){
                Node node = map.get(city);
                node.remove();
                node.addLast(tail);
                answer += 1;
            }
            else{
                answer += 5;
                Node node = new Node(city);
                node.addLast(tail);
                map.put(city,node);
                
                if (map.size() > cacheSize){
                    Node oldest = head.next;
                    oldest.remove();
                    map.remove(oldest.city);
                }
            }
            
        }
        
        return answer;
    }
}