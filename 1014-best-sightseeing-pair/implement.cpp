class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = 0;
        int l = 0;
        for(int i = 1; i < n; i++){
            int a = values[i]+i;
            int b = values[i]-i;
            ans = max(ans, values[l]+l + b);
            if(a > values[l]+l)
                l = i;
        }
        return ans;
    }
};