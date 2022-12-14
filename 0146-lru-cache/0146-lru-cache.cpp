class LRUCache {
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    int capacity;
    void changePosition(int key, int value){
        cache.erase(mp[key]);
        cache.push_front(make_pair(key, value));
        mp[key]=cache.begin();
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        auto found_itr = mp.find(key);
        if(found_itr !=mp.end()){
            cache.splice(cache.begin(), cache, found_itr->second);
            return found_itr->second->second;
        }else{
            return -1;
        }
    }
    void put(int key, int value) {
        auto found_itr = mp.find(key);
        if(found_itr!= mp.end()){
            cache.splice(cache.begin(),cache, found_itr->second);
            found_itr->second->second = value;
        }else{
            cache.push_front(make_pair(key, value));
            mp[key]=cache.begin();
            if(cache.size()>capacity){
                mp.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};

