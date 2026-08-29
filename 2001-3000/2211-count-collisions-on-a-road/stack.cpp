class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        stack<char> st;
        int ans = 0;
        for (char &c : directions) {
            if (st.empty() && c == 'L') continue;
            else if (st.empty()) st.push(c);
            else {
                if (c == 'L') {
                    bool stopped = false;
                    if (!st.empty() && st.top() == 'R') {
                        ans += 2;
                        st.pop();
                        stopped = true;
                    }
                    while (!st.empty() && st.top() == 'R') {
                        ans++;
                        st.pop();
                    }
                    if (!st.empty() && !stopped && st.top() == 'S') ans++;
                    if (st.empty() || (!st.empty() && st.top() != 'S')) st.push('S');
                } else if (c == 'S') {
                    while (!st.empty() && st.top() == 'R') {
                        ans++;
                        st.pop();
                    }
                    st.push(c);
                } else st.push(c);
            }
        }
        return ans;
    }
};