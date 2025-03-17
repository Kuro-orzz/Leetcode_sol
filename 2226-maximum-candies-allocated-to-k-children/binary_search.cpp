class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long l = 1, r = 1e12;
        long long ans = 0;
        while(l <= r){
            long long mid = (l+r) >> 1;
            long long sum = 0;
            for(int i = 0; i < n; i++)
                sum += candies[i] / mid;
            if(sum >= k){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};