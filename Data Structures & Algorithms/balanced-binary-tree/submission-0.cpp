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
private:
    pair<int, bool> dfs(TreeNode* node) {
        if (!node) return { 0, true };

        auto [lh, lb] = dfs(node->left);
        auto [rh, rb] = dfs(node->right);

        if (!lb || !rb) return { 1 + max(lh, rh), false };

        if (abs(lh - rh) > 1) return { 1 + max(lh, rh), false };

        return { 1 + max(lh, rh), true };
    }

public:
    bool isBalanced(TreeNode* root) {
        auto [h, b] = this->dfs(root);
        return b;
    }
};
