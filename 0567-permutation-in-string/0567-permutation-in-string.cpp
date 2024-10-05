class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v(26);
        mt19937 rng(time(0));
        for(int i = 0; i < 26; i++)
            v[i] = rng();
        vector<long long> pre(s2.size()+2);
        pre[0] = 0;
        for(int i = 1; i <= s2.size(); i++)
            pre[i] = pre[i-1]+v[s2[i-1]-'a'];
        long long t = 0;
        for(int i = 0; i < s1.size(); i++)
            t += v[s1[i]-'a'];
        for(int i = s1.size(); i <= s2.size(); i++)
            if(t == pre[i]-pre[i-s1.size()])
                return true;
        return false;
    }
};