class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> a(101, 0);
        int ans = 0;
        for(int i = nums.size()-1; i >= 0; i--){
            if(a[nums[i]] != 0){
                ans += (i+1) / 3;
                if((i+1) % 3 != 0)
                    ans++;
                break;
            }
            a[nums[i]]++;
        }
        return ans;
    }
};