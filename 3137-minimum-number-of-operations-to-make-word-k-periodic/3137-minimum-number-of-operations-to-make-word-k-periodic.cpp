class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> mp;
        for(int i = 0; i < word.size(); i+=k)
            mp[word.substr(i, k)]++;
        int ma = 0;
        int sum = 0;
        for(auto it : mp){
            ma = max(ma, it.second);
            sum += it.second;
        }
        return sum-ma;
    }
};