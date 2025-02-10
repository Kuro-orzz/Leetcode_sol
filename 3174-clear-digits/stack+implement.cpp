class Solution {
public:
    string clearDigits(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i]))
                st.pop();
            else
                st.push(i);
        }
        string ans;
        while(!st.empty()){
            ans += s[st.top()];
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};