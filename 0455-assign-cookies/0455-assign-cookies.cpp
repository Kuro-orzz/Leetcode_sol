class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int p1 = 0, p2 = 0;
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(p1 < g.size() && p2 < s.size()){
            while(p2 < s.size() && g[p1] > s[p2])
                p2++;
            if(p2 < s.size() && g[p1] <= s[p2]){
                ans++;
                p2++;
            }
            p1++;
        }
        return ans;
    }
};