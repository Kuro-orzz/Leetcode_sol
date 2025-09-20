class Solution {
public:
    bool check(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool doesAliceWin(string s) {
        int cnt = 0;
        vector<int> v;
        for (int i = 0; i < s.size(); i++){
            if ( check(s[i]) ){
                cnt++;
                v.push_back(i);
            }
        }
        return cnt;
    }
};