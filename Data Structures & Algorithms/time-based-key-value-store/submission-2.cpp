class TimeMap {
private:
    map<string, vector<pair<string, int>>> m;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        this->m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (this->m.find(key) == this->m.end()) return "";

        const auto& vals = this->m[key];
        int left = 0;
        int right = vals.size() - 1;

        string res_val = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            auto [curr_val, curr_time] = vals[mid];
            if (curr_time <= timestamp) {
                left = mid + 1;
                res_val = curr_val;
            } else {
                right = mid - 1;
            }
        }

        return res_val;
    }
};
