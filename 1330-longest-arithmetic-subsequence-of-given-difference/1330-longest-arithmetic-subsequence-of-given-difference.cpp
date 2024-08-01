class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int, int> mp;
        vector<int> dp(arr.size(), 1);
        mp[arr[0]] = 1;
        for(int i = 1; i < arr.size(); i++){
            if(mp[arr[i]-difference])
                dp[i] = dp[mp[arr[i]-difference]-1]+1;
            mp[arr[i]] = i+1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};