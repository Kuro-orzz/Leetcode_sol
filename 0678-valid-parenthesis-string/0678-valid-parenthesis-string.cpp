class Solution {
public:
    bool checkValidString(string s) {
        vector<int> star;
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')'){
                if(!st.empty())
                    st.pop();
                else if(star.size() > 0)
                    star.pop_back();
                else
                    return false;
            }
            else if(s[i] == '*')
                star.push_back(i);
        }
        while(!st.empty()){
            if(star.size() > 0 && star.back() > st.top())
                star.pop_back();
            else
                return false;
            st.pop();
        }
        return true;
    }
};