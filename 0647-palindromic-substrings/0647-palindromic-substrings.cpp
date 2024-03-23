class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = n;
        for(int i = 0; i < n; i++){
            string x = "";
            x += s[i];
            for(int j = i+1; j < n; j++){
                x += s[j];
                bool ok = true;
                int l = 0, r = x.length()-1;
                while(l < r){
                        if(x[l] == x[r]) l++, r--;
                        else{
                            ok = false;
                            break;
                        }
                    }
                if(ok)
                    ans++;
            }
        }
        return ans;
    }
};
