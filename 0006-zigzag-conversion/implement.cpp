class Solution {
public:
    string convert(string s, int numRows) {
        string a[1001];
        fill(a, a + numRows , "");
        int cnt_char = 0;
        while(1){
            for(int i = 0; i < numRows; i++){
                if(cnt_char == (int)s.length())
                    break;
                a[i] += s[cnt_char];
                cnt_char++; 
            }
            for(int i = numRows - 2; i > 0; i--){
                if(cnt_char == (int)s.length())
                    break;
                a[i] += s[cnt_char];
                cnt_char++;
            }
            if(cnt_char == (int)s.length())
                break;
        }
        string ans = "";
        for(int i = 0; i < numRows; i++)
            ans += a[i];
        return ans;
    }
};