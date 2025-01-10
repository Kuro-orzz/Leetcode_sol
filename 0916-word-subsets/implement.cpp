class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> fre(26, 0);
        for(int i = 0; i < words2.size(); i++){
            vector<int> v(26, 0);
            for(int j = 0; j < words2[i].size(); j++)
                v[words2[i][j]-'a']++;
            for(int j = 0; j < 26; j++)
                fre[j] = max(fre[j], v[j]);
        }
        vector<string> ans;
        for(int i = 0; i < words1.size(); i++){
            vector<int> v(26, 0);
            for(int j = 0; j < words1[i].size(); j++)
                v[words1[i][j]-'a']++;
            bool check = true;
            for(int j = 0; j < 26; j++)
                if(fre[j] > v[j]){
                    check = false;
                    break;
                }
            if(check) ans.push_back(words1[i]);
        }
        return ans;
    }
};