class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> v(nums.size()+1, 0);
        v[0]++;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & 1) cnt++;
            v[cnt]++;
        }
        int ans = 0;
        for(int i = k; i <= cnt; i++){
            ans += v[i]*v[i-k];
        }
        return ans;
    }
};