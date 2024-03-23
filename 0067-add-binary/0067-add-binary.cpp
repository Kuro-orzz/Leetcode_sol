class Solution {
public:
    string addBinary(string a, string b) {
        auto sum = [&](char x, char y, int &memo){
            if((x == '1' && y == '0') || (x == '0') && (y == '1'))
                return '1';
            else if(x == '1' && y == '0')
                return '0';
            else if(x == '0' && y == '0')
                return '0';
            else{
                memo = 1;
                return '0';
            }
        };
        string ans = "";
        if(a.size() > b.size()){
            string tmp = "";
            for(int i = 0; i < a.size()-b.size(); i++)
                tmp += '0';
            b = tmp + b;
        }
        else if(a.size() < b.size()){
            string tmp = "";
            for(int i = 0; i < b.size()-a.size(); i++)
                tmp += '0';
            a = tmp + a;
        }
        int memo = 0;
        cout << a << " " << b << endl;
        for(int i = a.size()-1; i >= 0; i--){
            char c;
            if(memo == 1){
                if(a[i] != '1' || b[i] != '1')
                    memo = 0;
                c = sum(a[i], b[i], memo);
                c = sum(c, '1', memo);
            }
            else
                c = sum(a[i], b[i], memo);
            cout << a[i] << " " << b[i] << " " << c << " " << memo << endl;
            ans += c;
        }
        if(memo == 1)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;        
    }
};