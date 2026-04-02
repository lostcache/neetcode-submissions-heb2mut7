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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) return true;
        if (root == nullptr || subRoot == nullptr) return false;

        int sub_tree_height = this->getHeight(subRoot);
        int main_tree_height = this->getHeight(root);

        return this->isSubtreeHelper(main_tree_height, sub_tree_height, root, subRoot);
    }

private:
    int getHeight(TreeNode* n) {
        if (n == nullptr) return 0;
        return max(this->getHeight(n->left), this->getHeight(n->right)) + 1;
    }

    bool isSubtreeHelper(int h, int sh, TreeNode* n, TreeNode* sn) {
        if (n == nullptr && sn == nullptr) return true;
        if (n == nullptr || sn == nullptr) return false;
        
        if (h == sh) {
            return this->isSameTree(n, sn);
        }

        return isSubtreeHelper(h - 1, sh, n->left, sn) ||
            isSubtreeHelper(h - 1, sh, n->right, sn);
    }

    bool isSameTree(TreeNode* n1, TreeNode* n2) {
        if (n1 == nullptr && n2 == nullptr) return true;
        if (n1 == nullptr || n2 == nullptr) return false;
        if (n1->val != n2->val) return false;
        return this->isSameTree(n1->left, n2->left) && this->isSameTree(n1->right, n2->right);
    }
};
