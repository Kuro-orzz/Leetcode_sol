class Solution {
public:
    string getSmallestString(string s, int k) {
        if(k == 0)
            return s;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(k > 0){
                if(s[i] == 'z'){
                    ans += 'a';
                    k--;
                }
                else{
                    if(k >= s[i]-'a' || k >= 'z'-s[i]+1){
                        ans += 'a';
                        k -= min(s[i]-'a', 'z'-s[i]+1);
                    }
                    else{
                        ans += s[i]-k;
                        k = 0;
                    }
                }
            }
            else
                ans += s[i];
        }
        return ans;
    }
};