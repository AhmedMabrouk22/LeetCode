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
public class Solution 
{
    public TreeNode? BuildTree(int[] inorder, int[] postorder)
    {
        var n = inorder.Length;

        var inorderMap = new Dictionary<int, int>();
        for (var i = 0; i < n; i++)
        {
            inorderMap[inorder[i]] = i;
        }

        var pIndex = n - 1;

        return construct(0, n - 1, postorder, ref pIndex, inorderMap);
    }

    TreeNode construct(int start, int end, int[] postorder, ref int refIndex, IReadOnlyDictionary<int, int> inorderMap)
    {
        if (start > end)
        {
            return null;
        }

        var root = new TreeNode(postorder[refIndex--]);

        var index = inorderMap[root.val];

        root.right = construct(index + 1, end, postorder, ref refIndex, inorderMap);
        root.left = construct(start, index - 1, postorder, ref refIndex, inorderMap);

        return root;
    }
}