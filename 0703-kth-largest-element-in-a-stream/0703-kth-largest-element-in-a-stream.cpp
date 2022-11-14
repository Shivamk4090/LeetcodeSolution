class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int x, vector<int>& nums) {
        for(auto e: nums){
          pq.push(e);
            if(pq.size()>x){
                pq.pop();
            }
        }
        k = x;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>k)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */