#define ll long long
class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n = v.size();
        stack<int> st;
        vector<ll> ans(n, 0);
        for(int i = 0; i < n; i++){
            if(st.empty())
                st.push(i);
            else{
                while(!st.empty() && v[st.top()] > v[i]){
                    int j = st.top();
                    st.pop();
                    ans[j] += (i-j)*v[j];
                }
                st.push(i);
            }
        }
        int sz1 = st.top()+1;
        while(!st.empty()){
            int t = st.top(); st.pop();
            ans[t] += (sz1-t)*v[t];
        }
        for(int i = n-1; i >= 0; i--){
            if(st.empty())
                st.push(i);
            else{
                while(!st.empty() && v[st.top()] > v[i]){
                    int j = st.top();
                    st.pop();
                    ans[j] += (j-i-1)*v[j];
                }
                st.push(i);
            }
        }
        int sz2 = st.top()-1;
        while(!st.empty()){
            int t = st.top(); st.pop();
            ans[t] += (t-sz2-1)*v[t];
        }
        ll res = 0;
        for(int i = 0; i < n; i++)
            res = max(res, ans[i]);
        return res;
    }
};