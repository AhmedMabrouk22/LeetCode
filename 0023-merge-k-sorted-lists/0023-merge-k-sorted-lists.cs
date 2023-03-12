/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode MergeKLists(ListNode[] lists) {
        var list = new List<int>();
        foreach (var i in lists)
        {
            var x = i;
            while(x != null)
            {
                list.Add(x.val);
                x = x.next;
            }
        }
        
        if (list.Count < 1)
            return null;
        list.Sort();
                
        ListNode head = new ListNode(list[0]);
        ListNode cur;
        if (list.Count >= 2)
        {
            cur = new ListNode(list[1]);
            head.next = cur;
            for (int i = 2; i < list.Count; ++i)
            {
                var temp = new ListNode(list[i]);
                cur.next = temp;
                cur = temp;
            }
        }

        return head;
    }
}