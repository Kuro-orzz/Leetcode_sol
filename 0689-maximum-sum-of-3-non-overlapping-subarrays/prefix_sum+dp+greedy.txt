#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n-k+1);
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(i < k-1) continue;
            else if(i > k-1) sum -= nums[i-k];
            pre[i-k+1] = sum;
        }
        vector<pii> maxL(n-k+1), maxR(n-k+1);
        pii mxL = {INT_MIN, -1};
        pii mxR = {INT_MIN, -1};
        for(int i = 0; i < n-k+1; i++){
            if(pre[i] > mxL.fi) mxL = {pre[i], i};
            maxL[i] = mxL;
            if(pre[n-k-i] >= mxR.fi) mxR = {pre[n-k-i], n-k-i};
            maxR[n-k-i] = mxR;
        }
        int maxVal = 0;
        vector<int> ans;
        for(int i = 0; i <= n-3*k; i++){
            if(maxVal < maxL[i].fi + pre[k+i] + maxR[2*k+i].fi){
                maxVal = maxL[i].fi + pre[k+i] + maxR[2*k+i].fi;
                ans = {maxL[i].se, k+i, maxR[2*k+i].se};
            }
        }
        return ans;
    }
};