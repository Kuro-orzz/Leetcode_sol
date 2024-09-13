class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        set<char> s;
        for(char c : allowed)
            s.insert(c);
        for(int i = 0; i < words.size(); i++){
            bool t = true;
            for(int j = 0; j < words[i].size(); j++)
                if(!s.count(words[i][j]))
                    t = false;
            if(t) ans++;
        }
        return ans;
    }
};