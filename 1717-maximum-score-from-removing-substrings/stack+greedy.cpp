class Solution {
public:
    int rmStr(string &s, char c1, char c2, int p) {
        int res = 0;
        stack<char> st;
        for (int i = 0; i < (int)s.size(); i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else if (st.top() == c1 && s[i] == c2) {
                st.pop(); res += p;
            } else {
                st.push(s[i]);
            }
        }
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return res;
    }

    int maximumGain(string s, int x, int y) {
        if (x > y) return rmStr(s, 'a', 'b', x) + rmStr(s, 'b', 'a', y);
        return rmStr(s, 'b', 'a', y) + rmStr(s, 'a', 'b', x);
    }
};