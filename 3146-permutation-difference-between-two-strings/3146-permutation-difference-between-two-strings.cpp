class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
            ans += abs(i-(int)s.find(t[i]));
        return ans;
    }
};