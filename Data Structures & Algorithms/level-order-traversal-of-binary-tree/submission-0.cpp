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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>();
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while (!q.empty()) {
            vector<int> vec;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto n = q.front();
                q.pop();
                if (n->left != nullptr) q.push(n->left);
                if (n->right != nullptr) q.push(n->right);
                vec.push_back(n->val);
            }
            res.push_back(vec);
        }
        return res;
    }
};
