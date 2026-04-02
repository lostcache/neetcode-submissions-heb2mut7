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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;

        this->invert(root);

        return root;
    }
private:
    void invert(TreeNode* node) {
        if (node == nullptr) return;

        invert(node->left);
        invert(node->right);

        auto temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};
