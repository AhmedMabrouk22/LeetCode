class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    priority_queue<double>small , large;
    // Small --> Max heap
    // Large --> Min heap
    
    void addNum(int num) 
    {
        if (small.empty() || num <= small.top())
            small.push(num);
        else 
            large.push(-num);
        
        if (small.size() > large.size() + 1)
        {
            large.push(-small.top());
            small.pop();
        }
        
        if (large.size() > small.size() + 1)
        {
            small.push(-large.top());
            large.pop();
        }
        
        
    }
    
    double findMedian() 
    {
        if (small.size() == large.size())
            return (small.top() + -large.top()) / 2;
        
        if (small.size() >= large.size() + 1)
            return small.top();
        
        return -large.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */