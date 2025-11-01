class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> sorted_word;
        for (string s : words) {
            sort(s.begin(), s.end());
            sorted_word.push_back(s);
        }
        vector<string> ans;
        int prev = 0, next = 1;
        while (next < n) {
            if (sorted_word[prev] == sorted_word[next]) next++;
            else {
                ans.push_back(words[prev]);
                prev = next;
                next++;
            }
        }
        ans.push_back(words[prev]);
        return ans;
    }
};