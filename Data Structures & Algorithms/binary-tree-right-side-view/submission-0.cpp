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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len - 1; ++i) {
                TreeNode* front = q.front();
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
                q.pop();
            }

            TreeNode* right_node = q.front();
            res.push_back(right_node->val);
            if (right_node->left) q.push(right_node->left);
            if (right_node->right) q.push(right_node->right);
            q.pop();
        }

        return res;
    }
};