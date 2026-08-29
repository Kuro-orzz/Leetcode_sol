class Solution {
public:
    string sortVowels(string s) {
        set<char> vowel = {'a', 'i', 'u', 'e', 'o', 'A', 'I', 'U', 'E', 'O'};
        vector<char> v;
        vector<int> pos;
        for (int i = 0; i < (int)s.size(); i++) {
            if (vowel.count(s[i])) {
                v.push_back(s[i]);
                pos.push_back(i);
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < (int)pos.size(); i++) {
            s[pos[i]] = v[i];
        }
        return s;
    }
};