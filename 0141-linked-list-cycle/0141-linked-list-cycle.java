/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        Map<ListNode,Boolean> mp = new HashMap<>();
        while(head != null) {
            if (!mp.containsKey(head)) 
                mp.put(head,true);
            else return true;
            head = head.next;
        }
        
        return false;
    }
}