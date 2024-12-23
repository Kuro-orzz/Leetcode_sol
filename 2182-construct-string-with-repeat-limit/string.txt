class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        sort(s.begin(), s.end(), greater<char>());
        int cnt = 1;
        int p = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]) cnt++;
            else cnt = 1;
            if(cnt > repeatLimit){
                p = max(p, i+1);
                bool ch = false;
                for(int j = p; j < s.size(); j++){
                    if(s[j] != s[i]){
                        swap(s[j], s[i]);
                        ch = true;
                        p = j;
                        break;
                    }
                }
                if(!ch) return s.substr(0, i);
            }
        }
        return s;
    }
};