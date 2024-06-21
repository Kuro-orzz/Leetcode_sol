class Solution {
public:
    int addDigits(int num) {
        while(num > 9){
            string s = to_string(num);
            num = 0;
            for(int i = 0; i < s.size(); i++)
                num += s[i]-'0';
        }
        return num;
    }
};