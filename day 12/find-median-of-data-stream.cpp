// level - hard
// https://leetcode.com/problems/find-median-from-data-stream/description/

//                  tc          sc
// addNum(int num)	O(log N)	O(N)
// findMedian()	    O(1)	    O(N)

class MedianFinder {
public:
    priority_queue<int> maHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() { }
    
    void addNum(int num) {
        if(maHeap.empty() || num < maHeap.top()) {
            maHeap.push(num);
        }
        else {
            minHeap.push(num);
        }

        if(maHeap.size() < minHeap.size()) {
            maHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if(maHeap.size() - minHeap.size() > 1) {
            minHeap.push(maHeap.top());
            maHeap.pop();
        }
    }
    
    double findMedian() {
        int n1 = maHeap.size();
        int n2 = minHeap.size();

        if((n1 + n2) % 2 == 0) {
            return (maHeap.top() + minHeap.top()) / 2.0;
        }

        return maHeap.top() * 1.0;
    }
};