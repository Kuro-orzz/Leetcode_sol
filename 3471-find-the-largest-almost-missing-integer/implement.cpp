class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size()-k+1; i++){
            set<int> s;
            for(int j = i; j < i+k; j++)
                s.insert(nums[j]);
            for(int val : s)
                mp[val]++;
        }
        int ans = -1e9;
        for(auto it : mp)
            if(it.second == 1)
                ans = max(ans, it.first);
        if(ans != -1e9) return ans;
        return -1;
    }
};