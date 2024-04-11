class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k)
            return "0";
        stack<int> st;
        for(int i = 0; i < num.size(); i++){
            if(st.empty())
                st.push(i);
            else{
                while(k && !st.empty() && num[i] < num[st.top()]){
                    st.pop();
                    k--;
                }
                st.push(i);
            }
        }
        while(k > 0){
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty()){
            ans += num[st.top()];
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int check = 0;
        while(ans[check] == '0')
            check++;
        if(check == ans.size())
            return "0";
        return ans.substr(check);
    }
};