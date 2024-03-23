class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int cnt1 = 0;
        int cnt2 = 0;
        string ans = "";
        for(int i = 0; cnt1 < n && cnt2 < m; i++){
            if(i % 2 == 0){
                ans += word1[cnt1];
                cnt1++;
            }
            else{
                ans += word2[cnt2];
                cnt2++;
            }
        }
        if(n <= m){
            for(int i = cnt2; i < m; i++)
                ans += word2[i];
        }
        else{
            for(int i = cnt1; i < n; i++)
                ans += word1[i];
        }
        return ans;
    }
};