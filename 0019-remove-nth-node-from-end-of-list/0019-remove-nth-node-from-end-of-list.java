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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int sz = 0;
        for (ListNode cur = head; cur != null ; cur = cur.next) ++sz;
        
        if (n == sz) {
            return head = head.next;
        }
        
        int x = sz - n;
        ListNode prv = null;
        int idx = 0;
        ListNode cur = head;
        while (cur != null) {
            if (idx == x) {
                prv.next = cur.next;
                cur = cur.next;
                break;
            }
            prv = cur;
            cur = cur.next;
            ++idx;
        }
        return head;
    }
}