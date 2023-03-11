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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    List<int> list = new List<int>();

    TreeNode Insert(int l, int r)
    {
        if (l == r)
            return null;
        var mid = (l + r) >> 1;
        return new TreeNode
        {
            val = list[mid],
            left = Insert(l, mid),
            right = Insert(mid + 1, r)
        };
    }

    public TreeNode SortedListToBST(ListNode head)
    {
        var node = head;
        while (node != null)
        {
            list.Add(node.val);
            node = node.next;
        }

        return Insert(0, list.Count);
    }

}