class Solution {
public:
    int sumDigit(int num){
        int res = 0;
        while(num){
            res += num%10;
            num /= 10;
        }
        return res;
    }

    int maximumSum(vector<int>& nums) {
        vector<pair<int, int>> v;
        for(int x : nums)
            v.push_back({sumDigit(x), x});
        sort(v.begin(), v.end());
        int ans = -1;
        for(int i = 1; i < v.size(); i++)
            if(v[i].first == v[i-1].first)
                ans = max(ans, v[i].second+v[i-1].second);
        return ans;
    }
};