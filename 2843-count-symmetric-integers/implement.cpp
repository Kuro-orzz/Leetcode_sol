class Solution {
public:
    bool check(int x){
        string s = to_string(x);
        if(s.size() % 2) return false;
        int fi = 0;
        for(int i = 0; i < s.size()/2; i++)
            fi += s[i]-'0';
        int se = 0;
        for(int i = s.size()/2; i < s.size(); i++)
            se += s[i]-'0';
        return fi == se;
    }

    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; i++){
            if(check(i)) ans++;
        }
        return ans;
    }
};