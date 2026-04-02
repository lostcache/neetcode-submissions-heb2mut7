class Solution {
public:

    string encode(vector<string>& strs) {
        string sizes = "";
        string concetnatedStrs = "";
        for (const auto& str: strs) {
            sizes += to_string(str.length()) + ',';
            concetnatedStrs += str;
        }
        return sizes + "#" + concetnatedStrs;
    }

    vector<string> decode(string s) {
        cout << s << endl;
        vector<string> res;
        vector<int> sizes;
        int idx = 0;
        while (idx < s.length() && s[idx] != '#') {
            string lengthStr = "";
            while (isdigit(s[idx])) { 
                lengthStr.push_back(s[idx]);
                idx++;
            }
            int length = stoi(lengthStr);
            sizes.push_back(length);
            idx++;
        }

        idx++;

        for (const auto size: sizes) {
            res.push_back(s.substr(idx, size));
            idx+=size;
        }
        return res;
    }
};
