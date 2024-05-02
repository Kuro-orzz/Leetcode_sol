class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
            if(s.find(-nums[i]) != s.end())
                ans = max(ans, abs(nums[i]));
        }
        return (ans ? ans : -1);
    }
};