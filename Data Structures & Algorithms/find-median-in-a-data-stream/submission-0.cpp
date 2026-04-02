class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> maxEle;
    priority_queue<int, vector<int>, less<int>> minEle;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (minEle.empty()) {
            minEle.push(num);
            return;
        }

        if (num > minEle.top()) {
            maxEle.push(num);
            while (maxEle.size() > minEle.size()) {
                minEle.push(maxEle.top());
                maxEle.pop();
            }
        } else {
            minEle.push(num);
            while (minEle.size() > maxEle.size()) {
                maxEle.push(minEle.top());
                minEle.pop();
            }
        }
        // if (minEle.size() > 0) {
        //     cout << "min: " << minEle.top() << ' ';
        // }
        // if (maxEle.size() > 0) {
        //     cout << "max: " << maxEle.top();
        // }
        // cout << endl;
    }
    
    double findMedian() {
        // cout << minEle.size() << ' ' << maxEle.size() << endl;
        if (minEle.size() == maxEle.size()) {
            return ((double)minEle.top() + (double)maxEle.top()) / 2;
        } else if (minEle.size() > maxEle.size()) {
            return minEle.top();
        } else {
            return maxEle.top();
        }
    }
};
