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
    bool isValidBST(TreeNode* root) {
        return this->isValidBSTHelper(LONG_MIN, LONG_MAX, root);
    }

private:
    bool isValidBSTHelper(long min, long max, TreeNode* n) {
        if (n == nullptr) return true;
        if (n->val <= min || n->val >= max) return false;
        return this->isValidBSTHelper(min, n->val, n->left) &&
            this->isValidBSTHelper(n->val, max, n->right);
    }
};
