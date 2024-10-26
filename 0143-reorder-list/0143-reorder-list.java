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
    public void reorderList(ListNode head) {
        
        if (head.next == null) return;
        
        ListNode slow = head;
        ListNode fast = head;
        ListNode prv = head;

        // when fast node reach to the end
        // the slow node will be in the middle

        while (fast != null && fast.next != null) {
            prv = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        prv.next = null;

        // reverse the second half part of list

        ListNode cur = slow;
        ListNode nxt = null;
        ListNode prev = null;

        while (cur != null) {
            nxt = cur.next;
            cur.next = prev;
            prev = cur;
            cur = nxt;
        }

        // merge the first part with the second part

        ListNode first = head;
        ListNode firstNxt = null;
        ListNode secondNxt = null;
        while (first != null && prev != null) {
            firstNxt = first.next;
            secondNxt = prev.next;
            first.next = prev;
            if (firstNxt != null)
                prev.next = firstNxt;

            first = firstNxt;
            prev = secondNxt;
        }
    }
}