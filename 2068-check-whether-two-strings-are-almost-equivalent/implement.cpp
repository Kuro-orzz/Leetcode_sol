class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        map<char, int> mp1, mp2;
        for(char c : word1)
            mp1[c]++;
        for(char c : word2)
            mp2[c]++;
        for(char i = 'a'; i <= 'z'; i++)
            if(abs(mp1[i]-mp2[i]) > 3)
                return false;
        return true;
    }
};