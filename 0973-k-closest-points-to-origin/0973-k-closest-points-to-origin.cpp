class Solution {
public:
    int dist(int x, int y){
        return (x*x) + (y*y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,vector<int>>> pq;
        for(auto e:points){
            int d = dist(e[0], e[1]);
            pq.push({d, {e[0], e[1]}});
            if(pq.size()>k){
                pq.pop();
            }
            
        }
        
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};