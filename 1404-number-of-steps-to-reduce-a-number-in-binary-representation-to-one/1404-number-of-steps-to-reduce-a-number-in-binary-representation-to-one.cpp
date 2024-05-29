class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        for(int i = s.size()-1; i > 0; i--){
            if(s[i] == '1'){
                int j = i;
                while(j > 0 && s[j] == '1')
                    j--;
                if(s[j] == '1')
                    s = '1' + s, i++;
                else
                    s[j] = '1';
                for(int k = j+1; k <= i; k++)
                    s[k] = '0';
                ans++;
            }
            ans++;
        }
        return ans;
    }
};