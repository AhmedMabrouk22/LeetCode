/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
function solve(leftSubTree , rightSubTree) {
    if (leftSubTree === null && rightSubTree === null)
        return true;
    else if (leftSubTree !== null && rightSubTree !== null) {
        let c1 = solve(leftSubTree.left,rightSubTree.right);
        let c2 = solve(leftSubTree.right,rightSubTree.left);
        let c3 = leftSubTree.val === rightSubTree.val;
        return c1&&c2&&c3;
    }
    return false;
}

var isSymmetric = function(root) {
    return root === null || solve(root.left,root.right);
};