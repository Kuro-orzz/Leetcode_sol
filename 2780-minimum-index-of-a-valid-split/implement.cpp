class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int x : nums)
            mp[x]++;
        int mx_fre = 0;
        for(auto it : mp)
            if(it.second > mp[mx_fre])
                mx_fre = it.first;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == mx_fre) cnt++;
            if(2*cnt > i+1 && 2*(mp[mx_fre]-cnt) > n-i-1)
                return i;
        }
        return -1;
    }
};