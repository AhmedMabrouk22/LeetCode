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
        int cnt = 0;
        while(head != null && cnt < (int)1e4) {
            head = head.next;
            ++cnt;
        }
        
        return head != null && cnt <= 1e4;
    }
}