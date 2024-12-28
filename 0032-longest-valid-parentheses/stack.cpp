class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.length();
        if(n == 0)
            return 0;
        int a[n];
        for(int i = 0; i < s.length(); i++){
            if(st.empty()){
                if(s[i] == '(')
                    st.push(i);
                else
                    a[i] = 0;
            }
            else if(!st.empty()){
                if(s[i] == '(')
                    st.push(i);
                else{
                    a[st.top()] = 1;
                    st.pop();
                    a[i] = 1;
                }
            }
        }
        while(!st.empty()){
            a[st.top()] = 0;
            st.pop();
        }
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(a[i] == 1)
                cnt++;
            else
                cnt = 0;
            ans = max(ans, cnt);
        }
        return ans;
    }
};