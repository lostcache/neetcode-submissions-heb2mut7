class Solution {
public:
  int rob(TreeNode *root) {
    map<pair<TreeNode *, int>, int> mem;
    auto dfs = [&](auto &&self, TreeNode *node, bool prev_rob) {
      if (node == nullptr) {
        return 0;
      }

      if (mem.find({node, prev_rob}) != mem.end()) {
        return mem[{node, prev_rob}];
      }

      if (prev_rob) {
        mem[{node, prev_rob}] =
            self(self, node->left, false) + self(self, node->right, false);
      } else {
        mem[{node, prev_rob}] =
            max(self(self, node->left, false) + self(self, node->right, false),
                node->val + self(self, node->left, true) +
                    self(self, node->right, true));
      }
      return mem[{node, prev_rob}];
    };

    return max(dfs(dfs, root, false), dfs(dfs, root, true));
  }
};