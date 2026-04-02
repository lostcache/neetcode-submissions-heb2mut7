class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> s;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (const auto& n: nums) {
            this->s.push(n);
            if (this->s.size() > k) s.pop();
        }
    }
    
    int add(int val) {
        this->s.push(val);
        if (this->s.size() > this->k) s.pop();
        return s.top();
    }
};
