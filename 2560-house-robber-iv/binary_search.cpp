class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 1, r = 1e9;
        while(l < r){
            int mid = (l+r) >> 1;
            int cnt = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] <= mid){
                    cnt++;
                    i++;
                }
            }
            if(cnt < k) l = mid+1;
            else r = mid;
        }
        return l;
    }
};