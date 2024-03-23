class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int fre = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        for(auto it : mp){
            if(it.second > fre){
                fre = it.second;
                ans = it.second;
            }
            else if(it.second == fre)
                ans += it.second;
        }
        return ans;
    }
};