/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;

        unordered_set<int> vst;
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(node);
        mp[node] = new Node(node->val);
        vst.insert(node->val);

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            for (const auto nei: curr->neighbors) {
                if (mp.find(nei) == mp.end()) {
                    mp[nei] = new Node(nei->val);
                }
                mp[curr]->neighbors.push_back(mp[nei]);
                if (vst.find(nei->val) != vst.end()) continue;
                q.push(nei);
                vst.insert(nei->val);
            }
        }

        return mp[node];
    }
};
