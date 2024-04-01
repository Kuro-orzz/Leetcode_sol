class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int bit[32];
        int l = 0, r = 0;
        int ans = INT_MAX;
        if(k == 0)
            for(int i = 0; i < nums.size(); i++)
                if(nums[i] > 0)
                    return 1;
        auto check = [&](int k, int bit[]){
            long long tmp = 0;
                for(int i = 0; i < 32; i++)
                    if(bit[i])
                        tmp += (1 << i); 
            return tmp >= k;
        };
        memset(bit, 0, sizeof(bit));
        while(r < nums.size()){
            int tmp = nums[r];
            while(tmp){
                bit[__lg(tmp)]++;
                tmp -= (1 << __lg(tmp));
            }
            if(check(k, bit)){
                ans = min(ans, r-l+1);
                while(l < r && check(k, bit)){
                    ans = min(ans, r-l+1);
                    int tmp2 = nums[l];
                    while(tmp2){
                        bit[__lg(tmp2)]--;
                        tmp2 -= (1 << __lg(tmp2));
                    }
                    l++;
                }
                if(check(k, bit))
                    ans = min(ans, r-l+1);
            }
            r++;
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};