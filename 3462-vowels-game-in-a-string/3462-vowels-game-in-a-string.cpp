class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        vector<int> v;
        auto check = [&](char c){
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        };
        for(int i = 0; i < s.size(); i++){
            if(check(s[i])){
                cnt++;
                v.push_back(i);
            }
        }
        if(cnt == 0) return false;
        else return true;
    }
};