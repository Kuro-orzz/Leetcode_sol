class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int n = to_string(low).length();
        string s = string(n, '0');
        while(stoi(s) <= high){
            if(s[s.length()-1] == '9'){
                s[0] = '0';
                s += '0';
                n++;
            }
            s[0]++;
            for(int i = 1; i < n; i++)
                s[i] = s[i-1]+1;
            if(stoi(s) <= high && stoi(s) >= low)
                ans.push_back(stoi(s));
            if(s[0] == '1' && s[s.length()-1] == '9')
                break;
        }
        return ans;
    }
};