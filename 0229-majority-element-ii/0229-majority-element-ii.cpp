class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        unordered_map<int, int> mp;
        for(int x : nums)
            mp[x]++;
        vector<int> ans;
        for(pair<int, int> it : mp)
            if(it.second > nums.size()/3)
                ans.push_back(it.first);
        return ans;
    }
};