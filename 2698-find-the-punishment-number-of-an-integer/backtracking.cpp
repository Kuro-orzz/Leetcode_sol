class Solution {
public:
    bool check_punishment(int num, string s){
        int t = 0;
        for(int i = 0; i < s.size(); i++){
            t = t*10 + s[i]-'0';     
            if(t > num) return false;       
            if(check_punishment(num-t, s.substr(i+1)))
                return true;
        }
        return t == num;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(check_punishment(i, to_string(i*i)))
                ans += i*i;
        }
        return ans;
    }
};