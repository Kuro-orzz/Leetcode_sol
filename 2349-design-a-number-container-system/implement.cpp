class NumberContainers {
public:
    unordered_map<int, set<int>> t;
    unordered_map<int, int> mp;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp.count(index))
            t[mp[index]].erase(index);
        mp[index] = number;
        t[number].insert(index);
    }
    
    int find(int number) {
        if(t[number].size())
            return *t[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */