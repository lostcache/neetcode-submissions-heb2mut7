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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "X";

        string res = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (!curr) {
                res += "X,";
            } else {
                res += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "X") return nullptr;

        string strVal;
        stringstream ss(data);
        queue<TreeNode*> q;

        getline(ss, strVal, ',');
        TreeNode* root = new TreeNode(stoi(strVal));
        q.push(root);

        while (getline(ss, strVal, ',')) {
            TreeNode* curr = q.front();
            q.pop();

            if (strVal != "X") {
                TreeNode* left = new TreeNode(stoi(strVal));
                curr->left = left;
                q.push(left);
            }

            getline(ss, strVal, ',');
            if (strVal != "X") {
                TreeNode* right = new TreeNode(stoi(strVal));
                curr->right = right;
                q.push(right);
            }
        }

        return root;
    }
};
