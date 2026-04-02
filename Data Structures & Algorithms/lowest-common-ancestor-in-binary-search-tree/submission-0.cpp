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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (p == nullptr || q == nullptr) return root;
        vector<TreeNode*> path1, path2;
        this->getPath(root, p->val, path1);
        this->getPath(root, q->val, path2);
        TreeNode* lca = nullptr;
        for (int i = 0; i < min(path1.size(), path2.size()); ++i) {
            if (path1[i]->val == path2[i]->val) lca = path1[i];
        }
        return lca;
    }

private:
    bool getPath(TreeNode* n, int t, vector<TreeNode*>& p) {
        if (n == nullptr) return false;
        if (n->val == t)  {
            p.push_back(n);
            return true;
        }
        p.push_back(n);
        if (getPath(n->left, t, p) || getPath(n->right, t, p)) return true;
        p.pop_back();
        return false;
    }
};
