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
 * @return {number}
 */
let cnt = 0;
function solve(node) {
    cnt *= 10;
    cnt += node.val;
    if (node.left === null && node.right === null)
        return cnt;
    let res = 0;
    if (node.left !== null) {
        res += solve(node.left);
        cnt = parseInt(cnt / 10);
    }
    if (node.right !== null) {
        res += solve(node.right);
        cnt = parseInt(cnt / 10);
    }

    return res;
} 

var sumNumbers = function(root) {
    cnt = 0;
    return solve(root);
};