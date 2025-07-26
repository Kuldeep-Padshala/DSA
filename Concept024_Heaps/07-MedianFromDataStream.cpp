// 295. The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

// class MedianFinder {
//   priority_queue<int> maxHeap; // left half (max-heap)
//   priority_queue<int, vector<int>, greater<int>> minHeap; // right half (min-heap)
class Median{
public:
    MedianFinder() {
      // max heap ma smaller half numbers, max on top
      // min heap ma larger, smallest on top

      // if odd, return maxheap top
      // even. return avg of tops
    }
    
    void addNum(int num) {

      //add:  5       15         1           3             7
      //max:  [5]     [5]       [5, 1]      [3,1]       [7,3,1]
      //min:  []     [15]        [15]      [5, 15]       [1, 15]

        
      maxHeap.push(num);

      // every number in maxHeap <= every number in minHeap
      minHeap.push(maxHeap.top());
      maxHeap.pop();

      if (minHeap.size() > maxHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
      }
    }
    
    double findMedian() {

      if (maxHeap.size() > minHeap.size())
            return maxHeap.top();
        else
            return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */