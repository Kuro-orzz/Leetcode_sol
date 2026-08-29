#define pii pair<int, int>
#define fi first
#define se second

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> right;
    priority_queue<int> left;
    pii median = {-1e9, -1e9};

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (median.fi == -1e9) {
            median = {num, -1e9};
            return;
        }
        int mn_med = median.fi;
        int mx_med = max(median.fi, median.se);
        if (num >= mx_med) {
            right.push(num);
            if (median.se == -1e9) {
                median = {median.fi, right.top()};
                right.pop();
            } else {
                left.push(median.fi);
                median = {median.se, -1e9};
            }
        } else if (num <= mn_med) {
            left.push(num);
            if (median.se == -1e9) {
                median = {left.top(), median.fi};
                left.pop();
            } else {
                right.push(median.se);
                median = {median.fi, -1e9};
            }
        } else {
            left.push(median.fi);
            right.push(median.se);
            median = {num, -1e9};
        }
    }
    
    double findMedian() {
        return (median.fi + (median.se == -1e9 ? median.fi : median.se)) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */