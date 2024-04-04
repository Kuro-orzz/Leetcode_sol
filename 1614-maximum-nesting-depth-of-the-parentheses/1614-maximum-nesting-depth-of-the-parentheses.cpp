class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = 0, cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
                cnt++;
            }
            else if(s[i] == ')' && !st.empty()){
                st.pop();
                cnt--;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};