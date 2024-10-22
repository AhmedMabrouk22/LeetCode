/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        
        if (list1 == null) return list2;
        if (list2 == null) return list1;
        
        ListNode h1 = list1;
        ListNode h2 = list2;
        ListNode prv = null;
        while(h1 != null && h2 != null) {
            if (h1.val <= h2.val) {
                ListNode nxt = h1.next;
                h1.next = h2;
                if (prv != null) {
                    prv.next = h1;
                }
                prv = h1;
                h1 = nxt;
            } else {
                prv = h2;
                h2 = h2.next;
            }
        }
        
        if (h2 == null && h1 != null) prv.next = h1;
        else if (h1 == null && h2 != null) prv.next = h2;
        
        if (list1.val <= list2.val) return list1;
        return list2;
    }
}