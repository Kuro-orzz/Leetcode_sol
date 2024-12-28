class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int longest = 1;
        string ans = "";
        ans += s[0];
        for(int i = 0; i < n; i++){
            string x = "";
            x += s[i];
            for(int j = i+1; j < n; j++){
                x += s[j];
                if(x.length() > longest){
                    bool ok = true;
                    int l = 0, r = x.length()-1;
                    while(l < r){
                        if(x[l] == x[r]) l++, r--;
                        else{
                            ok = false;
                            break;
                        }
                    }
                    if(ok){
                        longest = x.length();
                        ans = x;  
                    }
                }
            }
        }
        return ans;
    }
};