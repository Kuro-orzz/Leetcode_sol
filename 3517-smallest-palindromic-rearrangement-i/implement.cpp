class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> mp;
        for(char c : s) mp[c]++;
        char odd = '0';
        string ans = "";
        for(auto it : mp){
            if(it.second % 2) odd = it.first;
            ans += string(it.second/2, it.first);
        }
        if(odd != '0') ans += odd;
        string x;
        if(odd == '0') x = ans;
        else x = ans.substr(0, ans.size()-1);
        reverse(x.begin(), x.end());
        ans += x;
        return ans;
    }
};