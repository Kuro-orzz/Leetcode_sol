class Solution {
public:
    int myAtoi(string s) {
        string x = "";
        bool num = false;
        bool dau = false;
        bool zero = false;
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= '1' && s[i] <= '9'){
                x += s[i];
                num = true;
            }
            else if(s[i] == '0'){
                if(num)
                    x += s[i];
                zero = true;
            }
            else if((s[i] == '-' || s[i] == '+') && !num && !dau && !zero){
                x += s[i];
                dau = true;
            }
            else if((s[i] == '-' || s[i] == '+') && (dau || num || zero))
                break;
            else if(s[i] >= 'a' && s[i] <= 'z')
                break;
            else if(s[i] >= 'A' && s[i] <= 'Z')
                break;
            else if(s[i] == '.' || (num && s[i] == ' '))
                break;
            else if(s[i] == ' ' && (num || zero || dau))
                break;
        }
        if(x == "" || x == "-" || x == "+")
            return 0;
        if(x.length() > 15 && x[0] != '-')
            return 1ll*0-(1<<31)-1;
        else if(x.length() > 15 && x[0]=='-')
            return 1ll*(1<<31);
        long long ans = stoll(x);
        if(ans < 1ll*(1<<31))
            ans = 1ll*(1<<31);
        if(ans > 1ll*0-(1<<31)-1)
            ans = 1ll*0-(1<<31)-1;
        return ans;
    }
};