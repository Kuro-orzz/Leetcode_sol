class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        for(int i = 1; i < s.size(); i++)
            if(s[i] == '1') ans++;
        int sum = ans + (s[0]=='1' ? 1 : 0);
        for(int i = 0; i < s.size()-1; i++){
            if(s[i] == '0') sum++;
            else sum--;
            ans = max(ans, sum);
        }
        return ans;
    }
};