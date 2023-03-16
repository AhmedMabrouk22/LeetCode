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
    int idx;
    Dictionary<int, int> dic = new Dictionary<int, int>();
    public TreeNode BuildTree(int[] preorder, int[] inorder)
    {
        if (preorder.Length == 0 || inorder.Length == 0)
            return null;
        for (int i = 0; i < inorder.Length; ++i)
            dic.Add(inorder[i], i);

        return findRoot(preorder, 0, preorder.Length - 1);
    }

    TreeNode findRoot(int[] preorder,int l, int r)
    {
        if (l > r)
            return null;
        var rootVal = preorder[idx++];
        var root = new TreeNode(rootVal);

        root.left = findRoot(preorder, l, dic[rootVal]-1);
        root.right = findRoot(preorder, dic[rootVal] + 1, r);
        return root;
    }
}