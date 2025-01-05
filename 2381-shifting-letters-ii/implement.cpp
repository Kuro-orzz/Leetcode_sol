class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> v(s.size()+1, 0);
        for(int i = 0; i < shifts.size(); i++){
            if(shifts[i][2] == 0){
                v[shifts[i][0]]--;
                v[shifts[i][1]+1]++;
            }
            else{
                v[shifts[i][0]]++;
                v[shifts[i][1]+1]--;
            }
        }
        v[0] %= 26;
        for(int i = 1; i < s.size(); i++){
            v[i] += v[i-1];
            v[i] %= 26;
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i]+v[i] > 'z') s[i] = s[i]+v[i]-26;
            else if(s[i]+v[i] < 'a') s[i] = s[i]+v[i]+26;
            else s[i] += v[i];
        }
        return s;
    }
};