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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> s;
        this->kthSmallestHelper(root, s, k);
        return s[s.size() - 1];
    }

private:
    void kthSmallestHelper(TreeNode* n, vector<int>& s, int k) {
        if (n == nullptr) return;

        this->kthSmallestHelper(n->left, s, k);

        if (s.size() >= k) return;

        s.push_back(n->val);

        if (s.size() >= k) return;

        this->kthSmallestHelper(n->right, s, k);
    }
};
