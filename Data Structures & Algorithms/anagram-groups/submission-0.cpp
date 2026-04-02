class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagrams;
        for (const auto& str: strs) {
            string copy = str;
            sort(copy.begin(), copy.end());
            anagrams[copy].push_back(str);
        }

        vector<vector<string>> res;
        for (const auto& [sorted, strs]: anagrams) {
            res.push_back(strs);
        }

        return res;
    }
};
