class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            if(isdigit(tokens[i][tokens[i].size()-1]))
                st.push(stoi(tokens[i]));
            else{
                int t = st.top();
                st.pop();
                if(tokens[i][0] == '+'){
                    t += st.top();
                    st.pop();
                }
                else if(tokens[i][0] == '-'){
                    t = st.top()-t;
                    st.pop();
                }
                else if(tokens[i][0] == '*'){
                    t *= st.top();
                    st.pop();
                }
                else if(tokens[i][0] == '/'){
                    t = st.top()/t;
                    st.pop();
                }
                st.push(t);
            }
        }
        return st.top();
    }
};