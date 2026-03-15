#define pii pair<int, int>
#define fi first
#define se second

class LRUCache {
public:
    int limit, cur_sz;
    vector<int> cache;
    unordered_map<int, pii> mp;

    LRUCache(int capacity) {
        cur_sz = 0;
        limit = capacity;
        cache.assign(1e4 + 6, -1);
        mp[-1] = {-1, 1 << 20};         // recent used
        mp[1 << 20] = {-1, 1 << 20};    // long time no used:))
    }

    void recent_used(int key) {
        if (mp.count(key)) {
            mp[mp[key].fi].se = mp[key].se;
            mp[mp[key].se].fi = mp[key].fi;
        }
        mp[key] = {-1, mp[-1].se};
        mp[mp[-1].se].fi = key;
        mp[-1].se = key;
    }

    void remove_least_used() {
        int key = mp[1 << 20].fi;
        mp[mp[key].fi].se = mp[key].se;
        mp[mp[key].se].fi = mp[key].fi;
        mp.erase(key);
        cache[key] = -1;
    } 
    
    int get(int key) {
        if (mp.count(key)) recent_used(key);
        return cache[key];
    }
    
    void put(int key, int value) {
        recent_used(key);
        if (cur_sz < limit) {
            if (cache[key] == -1) cur_sz++;
        } else {
            if (cache[key] == -1) remove_least_used();
        }
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */