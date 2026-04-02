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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() <= 0) return nullptr;
        int idx = 0;
        auto root = new TreeNode(preorder[idx]);
        idx++;
        int root_idx = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        root->left = this->buildTreeHelper(preorder, inorder, idx, 0, root_idx - 1);
        root->right = this->buildTreeHelper(preorder, inorder, idx, root_idx + 1, inorder.size() - 1);
        return root;
    }

private:
    TreeNode* buildTreeHelper(const vector<int>& preorder, const vector<int>& inorder, int& idx, int l, int r) {
        if (l > r) return nullptr;
        if (l == r) {
            idx++;
            return new TreeNode(inorder[l]);
        }
        auto root = new TreeNode(preorder[idx]);
        idx++;
        int root_idx = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        root->left = this->buildTreeHelper(preorder, inorder, idx, l, root_idx - 1);
        root->right = this->buildTreeHelper(preorder, inorder, idx, root_idx + 1, r);
        return root;
    }
};
