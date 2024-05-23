class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        auto cmp = [&](int a, int b){return abs(a) < abs(b);};
        sort(nums.begin(), nums.end(), cmp);
        int ans = (1 << n)-1;
        vector<int> v;
        bool check = true;
        for(int i = 0; i < (1 << n); i++){
            check = true;
            v.clear();
            for(int j = 0; j < n; j++){
                if(1 & (i >> j)){
                    v.push_back(nums[j]);
                    if(binary_search(v.begin(), v.end(), nums[j]-k)){
                        check = false;
                        break;
                    }
                }
            }
            if(!check)
                ans--;
        }
        return ans;
    }
};