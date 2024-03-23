class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.length()-1;
        while(s[l] == s[r] && l < r){
            while(l+1 < s.size() && s[l] == s[l+1])
                l++;
            while(r-1 >= 0  && s[r] == s[r-1])
                r--;
            if(l >= r)
                return 0;
            l++;
            r--;
        
        }
        if(l > r)
            return 0;
        return r-l+1;
    }   
};