class Solution {
public:
    string s;
    vector<int> dp;

    int calc(int pos){
        if(pos >= s.size()) return 1;
        if(s[pos] == '0') return 0;
        if(dp[pos] != -1) return dp[pos];
        if(pos < s.size()-1 && stoi(s.substr(pos, 2)) <= 26)
            return dp[pos] = calc(pos+1) + calc(pos+2);
        return dp[pos] = calc(pos+1);
    }

    int numDecodings(string s) {
        this->s = s;
        dp.clear();
        dp.resize(s.size(), -1);
        calc(0);
        return max(dp[0], 0);
    }
};