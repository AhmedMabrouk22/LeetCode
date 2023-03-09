/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode DetectCycle(ListNode head)
    {
        var dic = new Dictionary<ListNode,bool>();
        for(var cur = head; cur != null;cur = cur.next)
        {
            if (dic.ContainsKey(cur))
                return cur;
            dic.Add(cur, true);
        }

        return null;
    }
}