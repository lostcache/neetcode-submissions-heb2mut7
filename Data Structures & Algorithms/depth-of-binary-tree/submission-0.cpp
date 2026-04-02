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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        return getDepth(root);
    }

    int getDepth(TreeNode* node) {
        if (node == nullptr) return 0;

        int left_depth = getDepth(node->left);
        int right_depth = getDepth(node->right);

        return max(left_depth, right_depth) + 1;
    }
};
