class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string ans = "";
        for(char c : s){
            if(c == '('){
                st.push(c);
            }                
            else if(c == ')'){
                ans = "";
                while(!st.empty() && st.top() != '('){
                    ans += st.top(); 
                    st.pop();
                }
                st.pop();
                for(char t : ans)
                    st.push(t);
            }
            else
                st.push(c);
        }
        ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};