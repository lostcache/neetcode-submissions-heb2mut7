class MinStack {
private:
    vector<int> st;
    vector<int> minStack;

public:
    MinStack() {
        this->st = vector<int>();
        this->minStack = vector<int>();
    }
    
    void push(int val) {
        this->st.push_back(val);
        if (minStack.empty() || val <= minStack.back()) {
            this->minStack.push_back(val);
        }
    }
    
    void pop() {
        int curr = st.back();
        this->st.pop_back();

        if (curr == this->minStack.back()) {
            this->minStack.pop_back();
        }
    }
    
    int top() {
        return this->st.back();
    }
    
    int getMin() {
        return this->minStack.back();
    }
};
