class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int l = 0, r = 0;
        int ans = 0;
        while(r < n){
            mp[s[r++]]++;
            if(!mp['a'] || !mp['b'] || !mp['c'])
                continue;
            while(l < r && mp['a'] && mp['b'] && mp['c']){
                ans += n-r+1;
                mp[s[l++]]--;
            }
        }
        return ans;
    }
};