/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function createBinaryTree(descriptions: number[][]): TreeNode | null {
    const nodes = new Map();
    const children = new Set();
    for (const [parent, child, isLeft] of descriptions) {
        if (!nodes.has(parent))
            nodes.set(parent, new TreeNode(parent));
        if (!nodes.has(child))
            nodes.set(child, new TreeNode(child));
        children.add(child);
        if (isLeft === 1)
            nodes.get(parent).left = nodes.get(child);
        else
            nodes.get(parent).right = nodes.get(child);
    }
    for (const [val, node] of nodes) {
        if (!children.has(val))
            return node;
    }
    return null;
};
