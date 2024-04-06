class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> mark;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                st.push(i);
            else if(!st.empty() && s[i] == ')')
                st.pop();
            else if(st.empty() && s[i] == ')')
                mark.insert(i);
        }
        while(!st.empty()){
            mark.insert(st.top());
            st.pop();
        }
        string ans = "";
        for(int i = 0; i < s.size(); i++)
            if(mark.find(i) == mark.end())
                ans += s[i];
        return ans;
    }
};