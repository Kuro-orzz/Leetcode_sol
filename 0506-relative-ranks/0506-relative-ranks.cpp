#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        ordered_set os;
        for(int x : score)
            os.insert(x);
        int n = score.size();
        for(int x : score){
            if(x == *os.find_by_order(n-1))
                ans.push_back("Gold Medal");
            else if(x == *os.find_by_order(n-2))
                ans.push_back("Silver Medal");
            else if(x == *os.find_by_order(n-3))
                ans.push_back("Bronze Medal");
            else
                ans.push_back(to_string(n-os.order_of_key(x)));
        }
        return ans;
    }
};