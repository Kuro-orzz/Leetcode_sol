#define pii pair<int, int>
#define fi first
#define se second

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T, typename Compare = std::less<T>>
using ordered_set = tree<
    T,
    null_type,
    Compare,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

class Router {
public:
    int memoryLimit;
    // dest, [ts, src]
    unordered_map<int, ordered_set<pii>> pack;
    // src, dest, ts
    queue<vector<int>> q;

    void removeOldestPacket() {
        vector<int> packet = q.front(); q.pop();
        auto pos = pack[packet[1]].order_of_key({packet[2], packet[0]});
        auto it = pack[packet[1]].find_by_order(pos);
        pack[packet[1]].erase(it);
    }
    
    
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if (pack[destination].find({timestamp, source}) != pack[destination].end()) {
            return false;
        }
        if (q.size() == memoryLimit) {
            removeOldestPacket();
        }
        pack[destination].insert({timestamp, source});
        q.push({source, destination, timestamp});
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        vector<int> packet = q.front();
        removeOldestPacket();
        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it1 = pack[destination].order_of_key({startTime, 0});
        auto it2 = pack[destination].order_of_key({endTime+1, 0});
        return it2 - it1;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */