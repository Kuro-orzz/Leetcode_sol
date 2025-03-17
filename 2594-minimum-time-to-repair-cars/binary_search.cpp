class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0, r = 1e15+1;
        long long ans = LLONG_MAX;
        while(l <= r){
            long long mid = (l+r) >> 1;
            long long cnt = 0;
            for(int i = 0; i < ranks.size(); i++)
                cnt += (int)sqrt(mid/ranks[i]);
            if(cnt >= cars){
                r = mid-1;
                ans = mid;
            }
            else l = mid+1;
        }
        return ans;
    }
};