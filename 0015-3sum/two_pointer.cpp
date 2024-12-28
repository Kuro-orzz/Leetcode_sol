class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> v;
        for(int i = 0; i < nums.size(); i++){
            int l = i+1, r = nums.size()-1;
            while(l < r){
                if(nums[i]+nums[l]+nums[r] > 0)
                    r--;
                else if(nums[i]+nums[l]+nums[r] < 0)
                    l++;
                else{
                    v.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto it : v)
            ans.push_back(it);
        return ans;
    }
};