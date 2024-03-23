class Solution {
public:
int lengthOfLongestSubstring(string s) {
    map<char, int> mp;
    int res = 0;
    int cnt = 0;
    int pos = 0;
    for(int i = 0; i < s.length(); i++){
        if(mp[s[i]] == 0){
            cnt++;
            mp[s[i]] = i+1;
        }
        else{
            int tmp = mp[s[i]]-1;
            for(int j = pos; j < tmp+1; j++)
                mp[s[j]] = 0;
            pos = tmp + 1;
            cnt = i - (tmp);
            mp[s[i]] = i+1;
        }
        if(res < cnt)
            res = cnt;
    }
    return res;
}
};