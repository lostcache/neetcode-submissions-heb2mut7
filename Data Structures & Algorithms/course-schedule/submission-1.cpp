class Solution {
private:
    bool canFinHelper(auto& can_fin, auto& vst, const auto& pre, int currCourse) {
        if (vst[currCourse]) {
            return can_fin[currCourse];
        }
        vst[currCourse] = true;
        for (int req: pre[currCourse]) {
            if (!this->canFinHelper(can_fin, vst, pre, req)) {
                can_fin[req] = false;
                return can_fin[req];
            }
        }
        can_fin[currCourse] = true;
        return can_fin[currCourse];
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prere) {
        vector<vector<int>> pre(numCourses + 1, vector<int>());
        for (const auto& req_list: prere) {
            pre[req_list[0]].push_back(req_list[1]);
        }
        vector<bool> can_fin(numCourses + 1, false);
        unordered_set<int> vst;
        for (int i = 1; i < numCourses; ++i) {
            vector<bool> vst(numCourses + 1, false);
            if (!this->canFinHelper(can_fin, vst, pre, i)) {
                return false;
            }
        }
        return true;
    }
};
