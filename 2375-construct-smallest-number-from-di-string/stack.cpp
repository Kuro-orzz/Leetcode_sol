class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string s = string(n+1, '0');
        int val = 1;
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(st.empty()){
                if(pattern[i] == 'I')
                    s[i] = (char)(val++ + '0');
                else st.push(i);
            }
            else if(pattern[i] == 'I'){
                s[i] = (char)(val++ + '0');
                while(!st.empty()){
                    s[st.top()] = (char)(val++ + '0');
                    st.pop();
                }
            }
            else st.push(i);
        }
        s[n] = (char)(val++ + '0');
        while(!st.empty()){
            s[st.top()] = (char)(val++ + '0');
            st.pop();
        }
        return s;
    }
};