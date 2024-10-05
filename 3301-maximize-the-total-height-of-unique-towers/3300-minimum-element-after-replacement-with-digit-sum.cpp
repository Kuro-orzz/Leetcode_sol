class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        long long ans = 0;
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());
        int t = INT_MAX;
        for(int i = 0; i < maximumHeight.size(); i++){
            maximumHeight[i] = min(maximumHeight[i], t);
            t = maximumHeight[i]-1;
            if(maximumHeight[i] <= 0)
                return -1;
            ans += maximumHeight[i];
        }
        return ans;
    }
};