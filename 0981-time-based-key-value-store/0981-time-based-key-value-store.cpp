class TimeMap {
    unordered_map<string, vector<pair<int,string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
          if (mp.find(key) == mp.end()) {
            return "";
        }
        
        int i=0, j = mp[key].size()-1, n= j+1;
        
        while(i<=j){
            int mid = i+(j-i)/2;
            if(mp[key][mid].first==timestamp){
                return mp[key][mid].second;
            }
            else if (mp[key][mid].first<timestamp){
               i = mid+1;
            }else{
                 j = mid-1;
            }
        }
        // cout<<"i"<<i<<" j:"<<j<<endl;    
        if(i>j){
             if(i==n){
             return mp[key][j].second;       
            }
            else if(j==-1){
                return "";
            }
            else{
                if(mp[key][i].first>timestamp) return mp[key][j].second;
                else return mp[key][i].second;
            }
        }
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */