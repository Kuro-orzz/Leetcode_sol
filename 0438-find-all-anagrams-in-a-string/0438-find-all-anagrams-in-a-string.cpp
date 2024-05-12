class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size())
            return vector<int>();
        vector<int> t = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
        s = " " + s;
        p = " " + p;
        auto change = [&](char c){return t[c-'a'];};
        auto getHash= [&](int l, int r, vector<long long> &hash){
            return hash[r] - hash[l-1];
        };
        vector<long long> hashS(s.size());
        hashS[0] = 0;
        for(int i = 1; i < s.size(); i++)
            hashS[i] = hashS[i-1] + change(s[i])*change(s[i]);
        long long hashP = 0;
        for(int i = 1; i < p.size(); i++)
            hashP += change(p[i])*change(p[i]);
        vector<int> ans;
        for(int i = 1; i < s.size()-p.size()+2; i++){
            if(hashP == getHash(i, i+p.size()-2, hashS))
                ans.push_back(i-1);
        }
        return ans;
    }
};