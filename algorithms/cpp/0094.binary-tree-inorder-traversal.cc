// Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author : Junjie Huang
// Date   : 2021-03-27
/*******************************************************************************
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 *
 * Constraints:
 *    The number of nodes in the tree is in the range [0, 100].
 *    -100 <= Node.val <= 100
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 ******************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> sta;
        TreeNode* cur = root;
        while (cur || !sta.empty()) {
            if (cur) {
                sta.push(cur);
                cur = cur->left;
            } else {
                cur = sta.top();
                sta.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};
