class MedianFinder {
public:
    std::priority_queue<double> lo;
    std::priority_queue<double, std::vector<double>, std::greater<double>> hi;
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        lo.push(num);
        if (lo.size() > hi.size()) {
            hi.push(lo.top());
            lo.pop();
            if (lo.size() < hi.size()) {
                lo.push(hi.top());
                hi.pop();
            }
        }
    }
    
    double findMedian() {
        if (lo.size() == 0) {
            return 0;
        } else if (lo.size() > hi.size()) {
            return lo.top();
        } else {
            return (lo.top() + hi.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */