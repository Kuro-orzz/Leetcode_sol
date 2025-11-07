class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for(int i = 0; i < (1 << n); i++){
            int val = (i ^ (i >> 1));
            bitset<32> bin(val);
            ans.push_back(bin.to_ulong());
        }
        return ans;
    }
};