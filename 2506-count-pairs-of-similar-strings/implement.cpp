class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0;
        for(int i = 0; i < words.size(); i++)
            for(int j = i+1; j < words.size(); j++){
                unordered_set<char> s1, s2;
                for(char c : words[i])
                    s1.insert(c);
                for(char c : words[j])
                    s2.insert(c);
                if(s1 == s2) ans++;
            }
        return ans;
    }
};