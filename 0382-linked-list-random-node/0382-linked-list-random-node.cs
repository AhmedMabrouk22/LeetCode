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

    List<int> list = new List<int>();
    Random rand = new Random();
    public Solution(ListNode head)
    {

        var cur = head;
        while(cur != null)
        {
            list.Add(cur.val);
            cur = cur.next;
        }
    }

    public int GetRandom()
    {
        int n = list.Count;
        int pos = rand.Next(n);
        return list[pos];
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.GetRandom();
 */