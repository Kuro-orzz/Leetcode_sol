#pragma GCC optimize("O3, unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool __io_boost = [](){
    cin.tie(nullptr); cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);      
}();

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<int, int> mp;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        for(int i = 0; i < s.size(); i++)
            if(mp[t[i]])
                mp[t[i]]--;
            else
                return false;
        return true;
    }
};