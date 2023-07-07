/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
   public ArrayList<Integer> inorderTraversal(TreeNode root){
		ArrayList<Integer> res = new ArrayList<>();
		Stack<TreeNode> s = new Stack<>();
		
		TreeNode currentNode = root;
		boolean done = false;
		while(!done) {
			if(currentNode != null) {
				s.push(currentNode);
				currentNode = currentNode.left;
			} else {
				if(s.isEmpty()) {
					done = true;
				} else {
					currentNode = s.pop();
				}
                if (currentNode == null) {
                    done = true;
                    continue;
                }
				res.add(currentNode.val);
				currentNode = currentNode.right;
			}
		}
		
		return res;
	}
}
