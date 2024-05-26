class Solution {
public:    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> mp;
        for(int i : nums2)
            mp[i*k]++;
        long long ans = 0;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 1; j <= sqrt(nums1[i]); j++){
                if(nums1[i] % j == 0){
                    ans += mp[j];
                    if(j != nums1[i]/j)
                        ans += mp[nums1[i]/j];
                }
            }
        }
        return ans;
    }
};