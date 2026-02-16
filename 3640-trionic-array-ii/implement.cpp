class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long ans = -1e18;
        int l = 0, p = 0, q = 0, r = 0;
        while (l < n) {
            // inc1
            p = l + 1;
            while (p < n && nums[p-1] < nums[p]) p++;
            if (p == l + 1) { l++; continue; }
            long long sum1 = LLONG_MIN, tmp1 = 0;
            for (int i = p-2; i >= l; i--) {
                tmp1 += nums[i];
                sum1 = max(sum1, tmp1);
            }

            // dec
            q = p;
            long long sum2 = 0; 
            while (q < n && nums[q-1] > nums[q]) {
                sum2 += nums[q-1];
                q++;
            }
            if (q == p) { l = p; continue; }

            // inc2
            r = q;
            long long sum3 = LLONG_MIN, tmp3 = 0;
            while (r < n && nums[r-1] < nums[r]) {
                tmp3 += nums[r-1];
                sum3 = max(sum3, tmp3 + nums[r]);
                r++;
            }
            if (r == q) { l = q - 1; continue; }
            
            ans = max(ans, sum1 + sum2 + sum3);
            l = q - 1;
        }
        return ans;
    }
};