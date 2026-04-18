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
    vector<int> max_stack = {INT_MIN};
    int res = 0;

    void dfs(TreeNode* node) {
        if (!node) return;

        if (node->val >= max_stack.back()) {
            res++;
        }

        max_stack.push_back(max(max_stack.back(), node->val));

        dfs(node->left);
        dfs(node->right);

        max_stack.pop_back();
    }

public:
    int goodNodes(TreeNode* root) {
        this->dfs(root);
        return res;
    }
};
