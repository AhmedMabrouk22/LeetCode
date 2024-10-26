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
        Stack<ListNode> st = new Stack<>();
        for(ListNode cur = head; cur != null ; cur = cur.next)
            st.push(cur);

        int size = st.size();
        int idx = 0;
        ListNode nxt = null;
        ListNode tail;
        for(ListNode cur = head; cur != null ;) {
            if (idx == size / 2) {
                cur.next = null;
                break;
            }
            nxt = cur.next;
            tail = st.pop();
            cur.next = tail;
            tail.next = nxt;
            cur = nxt;
            ++idx;
        }

        for (ListNode cur = head; cur != null; cur = cur.next)
            System.out.print(cur.val + " ");
    }
}