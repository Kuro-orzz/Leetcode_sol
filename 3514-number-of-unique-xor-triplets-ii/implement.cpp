class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int> s(4096, 0);
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++)
                s[nums[i]^nums[j]] = 1;
        }
        unordered_set<int> ans;
        for(int i = 0 ; i <= 3000; i++){
            for(int x : nums){
                if(s[i ^ x])
                    ans.insert(i);
            }
        }
        for(int x : nums) ans.insert(x);
        return ans.size();
    }
};