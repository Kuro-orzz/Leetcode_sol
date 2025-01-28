class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        if(s1[0] != s2[0] || s1[0] != s3[0]) return -1;
        int mn_len = min({s1.size(), s2.size(), s3.size()});
        int last = 0;
        for(int i = 0; i < mn_len; i++){
            if(s1[i] != s2[i] || s1[i] != s3[i])
                break;   
            else last = i+1;
        }
        return s1.size()+s2.size()+s3.size()-3*last;
    }
};