class Solution {
public:
    string addStrings(string num1, string num2) {
        while(num1.length() < num2.length())
            num1 = '0' + num1;
        while(num1.length() > num2.length())
            num2 = '0' + num2;
        string res = "";
        int nho = 0;
        for(int i = num1.length()-1; i >= 0; i--){
            int x = num1[i]-'0'+num2[i]-'0'+nho;
            nho = 0;
            if(x < 10)
                res = (char)(x + '0') + res;
            else{
                nho = 1;
                res = (char)(x%10+'0') + res;
            }
        }
        if(nho)
            res = '1'+res;
        return res;
    }
};