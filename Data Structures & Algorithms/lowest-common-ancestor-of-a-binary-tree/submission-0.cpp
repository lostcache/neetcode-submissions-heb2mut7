class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> pp, pq;
    auto dfs = [&](auto &&self, TreeNode *node, vector<TreeNode *> &path,
                   TreeNode *tar, vector<TreeNode *> &stack) {
      if (node == nullptr) {
        return;
      }

      stack.push_back(node);

      if (node == tar) {
        path = stack;
        return;
      }

      self(self, node->left, path, tar, stack);
      self(self, node->right, path, tar, stack);

      stack.pop_back();
    };

    vector<TreeNode *> stack;
    dfs(dfs, root, pp, p, stack);
    stack.clear();
    dfs(dfs, root, pq, q, stack);

    TreeNode *res = root;
    int i = 0;
    while (i < pp.size() && i < pq.size() && pp[i] == pq[i]) {
      res = pp[i];
      i++;
    }

    return res;
  }
};