class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        auto multi = [&](string s, char c){
            string ans = "";
            int memo = 0;
            for(int i = s.size()-1; i >= 0; i--){
                int tmp = (s[i]-'0')*(c-'0')+memo;
                ans += (tmp%10)+'0';
                memo = tmp/10;
            }
            if(memo)
                ans += memo+'0';
            reverse(ans.begin(), ans.end());
            return ans;
        };
        auto sum = [&](string a, string b){
            while(a.size() < b.size()) a = '0'+a;
            while(a.size() > b.size()) b = '0'+b;
            string ans = "";
            int memo = 0;
            for(int i = a.size()-1; i >= 0; i--){
                int tmp = (a[i]-'0')+(b[i]-'0')+memo;
                ans += (tmp%10)+'0';
                memo = tmp/10;
            }
            if(memo)
                ans += memo+'0';
            reverse(ans.begin(), ans.end());
            return ans;
        };
        string memo[201];
        for(int i = num2.size()-1; i >= 0; i--){
            memo[i] = multi(num1, num2[i]); 
            string tmp = "";
            for(int j = 0; j < num2.size()-1-i; j++)
                tmp += '0';
            memo[i] = memo[i]+tmp;
        }
        string ans = "0";
        for(int i = 0; i < num2.size(); i++)
            ans = sum(ans, memo[i]);
        return ans;
    }
};