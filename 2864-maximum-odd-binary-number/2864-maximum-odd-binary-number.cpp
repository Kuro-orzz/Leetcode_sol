class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int zero = 0;
        int one = 0;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '0')
                zero++;
            else
                one++;
        return string(one-1, '1')+string(zero, '0')+'1';
    }
};