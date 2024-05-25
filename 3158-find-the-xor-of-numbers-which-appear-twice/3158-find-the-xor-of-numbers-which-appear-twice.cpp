class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        map<int, int> mp;
        for(int i : nums)
            mp[i]++;
        int ans = 0;
        for(auto it : mp)
            if(it.second == 2)
                ans ^= it.first;
        return ans;
    }
};