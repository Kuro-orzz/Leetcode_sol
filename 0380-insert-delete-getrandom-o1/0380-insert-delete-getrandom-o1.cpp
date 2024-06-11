#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
class RandomizedSet {
public:
    ordered_set s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val) == s.end()){
            s.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(s.find(val) != s.end()){
            s.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int num = rand() % s.size();
        return *s.find_by_order(num);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */