class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        string ans = "";
        for(int i = 0; i < order.size(); i++)
            while(mp[order[i]] > 0){
                ans += order[i];
                mp[order[i]]--;
            }
        for(int i = 0; i < s.size(); i++)
            if(mp[s[i]] > 0)
                ans += s[i];
        return ans;
    }
};