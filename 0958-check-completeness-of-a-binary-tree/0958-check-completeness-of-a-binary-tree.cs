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
    public bool IsCompleteTree(TreeNode root)
    {
        var q = new Queue<TreeNode>();
        q.Enqueue(root);
        while(q.Count > 0)
        {
            var cur = q.Dequeue();
            if (cur != null)
            {
                q.Enqueue(cur.left);
                q.Enqueue(cur.right);
            }
            else
            {
                while(q.Count > 0)
                {
                    if (q.Dequeue() != null)
                        return false;
                }
            }
        }
        return true;
    }
}