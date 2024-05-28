class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int ans = 0;
        int l, r;
        l = r = 0;
        auto cal = [&](int i){return abs(s[i]-t[i]);};
        while(r < n){
            maxCost -= cal(r);
            r++;
            if(maxCost < 0){
                while(l < r && maxCost < 0)
                    maxCost += cal(l), l++;
            }
            ans = max(ans, r-l);
        }
        return ans;
    }
};