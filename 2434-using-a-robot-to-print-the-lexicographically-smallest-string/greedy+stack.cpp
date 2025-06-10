class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<int> cnt(26);
        for (char c : s) cnt[c-'a']++;
        stack<char> st;
        string ans = "";
        char mn = 'a';
        for (char c : s) {
            st.push(c); cnt[c-'a']--;
            while (mn != 'z' && !cnt[mn-'a']) mn++;
            while (!st.empty() && st.top() <= mn) {
                ans += st.top();
                st.pop();
            }
        }
        return ans;
    }
};