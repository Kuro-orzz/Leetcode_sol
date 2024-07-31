class Solution {
public:
    int minimumLength(string s) {
        map<int, int> mp;
        for(char c : s)
            mp[c]++;
        int ans = 0;
        for(auto it : mp){
            int t = it.second;
            while(t >= 3)
                t -= t/3*2;
            ans += t;
        }
        return ans;
    }
};