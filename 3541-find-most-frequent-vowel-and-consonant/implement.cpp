class Solution {
public:
    int maxFreqSum(string s) {
        map<char, int> vowel = {{'a', 0}, {'e', 0}, 
                             {'i', 0}, {'o', 0}, {'u', 0}};
        map<char, int> consonent;
        for (char c : s) {
            if (vowel.count(c)) vowel[c]++;
            else consonent[c]++;
        }
        int sum1 = 0, sum2 = 0;
        for (auto it : vowel) {
            sum1 = max(sum1, it.second);
        }
        for (auto it : consonent) {
            sum2 = max(sum2, it.second);
        }
        return sum1 + sum2;
    }
};