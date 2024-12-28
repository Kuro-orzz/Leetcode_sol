class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = 1e5;
        vector<long long> H(2e5+6);
        mt19937 rng(time(0));
        for(int i = 0; i < 2e5+6; i++)
            H[i] = rng();
        unordered_set<long long> v;
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++){
            int l = i+1, r = nums.size()-1;
            while(l < r){
                if(nums[i]+nums[l]+nums[r] > 0)
                    r--;
                else if(nums[i]+nums[l]+nums[r] < 0)
                    l++;
                else{
                    if(!v.count(H[nums[i]+N]*101+H[nums[l]+N]*107+H[nums[r]+N]*311)){
                        ans.push_back({nums[i], nums[l], nums[r]});
                        v.insert(H[nums[i]+N]*101+H[nums[l]+N]*107+H[nums[r]+N]*311);
                    }
                    l++;
                    r--;
                }
            }
        }
        return ans;
    }
};