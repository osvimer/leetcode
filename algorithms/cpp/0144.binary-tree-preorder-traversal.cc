// Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author : Junjie Huang
// Date   : 2021-03-28
/*******************************************************************************
 * Given the root of a binary tree, return the preorder traversal of its nodes'
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> sta;
        if (root) sta.push(root);
        while (!sta.empty()) {
            TreeNode* cur = sta.top();
            result.push_back(cur->val);
            sta.pop();
            if (cur->right) sta.push(cur->right);
            if (cur->left) sta.push(cur->left);
        }
        return result;
    }
};
