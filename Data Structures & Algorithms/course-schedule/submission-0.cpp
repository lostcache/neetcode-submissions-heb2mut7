class Solution {
private:
    bool canFinHelper(auto& vst, const auto& pre, int currCourse) {
        if (vst[currCourse]) {
            return false;
        }
        vst[currCourse] = true;
        for (int req: pre[currCourse]) {
            if (!this->canFinHelper(vst, pre, req)) {
                return false;
            }
        }
        vst[currCourse] = false;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prere) {
        vector<vector<int>> pre(numCourses + 1, vector<int>());
        for (const auto& req_list: prere) {
            pre[req_list[0]].push_back(req_list[1]);
        }
        for (int i = 1; i < numCourses; ++i) {
            vector<bool> vst(numCourses + 1, false);
            if (!this->canFinHelper(vst, pre, i)) {
                return false;
            }
        }
        return true;
    }
};
