class Solution {
public:
    int reverse(int x) {
        bool check;
        if(x >= 0)
            check = true;
        else
            check = false;
        string s = to_string(x);
        string tmp = "";
        for(int i = s.length()-1; i >= 0; i--)
            tmp += s[i];
        long long ans = stoll(tmp);
        if(!check)
            ans = 0 - ans;
        if(ans > 2147483647 || ans < -2147483648)
            return 0;
        else
            return ans;
    }
};