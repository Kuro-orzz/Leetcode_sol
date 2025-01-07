class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<vector<int>> v(10);
        vector<int> ans;
        long long t = 1;
        for(int i = 0; i < 10; i++){
            v = vector<vector<int>>(10);
            for(int j = 0; j < nums.size(); j++)
                v[(nums[j]+100000)/t%10].push_back(nums[j]);
            int idx = 0;
            for(int j = 0; j < 10; j++)
                for(int k = 0; k < v[j].size(); k++){
                    nums[idx] = v[j][k];
                    idx++;
                }
            t *= 10;
        }
        return nums;
    }
};