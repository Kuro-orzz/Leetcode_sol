class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(char c : s)
            mp[c]++;
        int ans = 0;
        bool odd = false;
        for(auto it : mp){
            if(it.second % 2 == 0)
                ans += it.second;
            else{
                ans += it.second-1;   
                odd = true;
            }
        }
        ans += (odd ? 1 : 0);
        return ans;
    }
};