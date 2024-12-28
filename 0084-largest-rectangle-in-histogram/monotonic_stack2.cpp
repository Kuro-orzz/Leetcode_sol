class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < heights.size(); i++){
            if(st.empty())
                st.push(i);
            else if(!st.empty() && heights[i] >= heights[st.top()])
                st.push(i);
            else{
                while(!st.empty() && heights[i] < heights[st.top()]){
                    int tmp = st.top();
                    st.pop();
                    int val = (i-tmp)*heights[tmp];
                    if(!st.empty())
                        val += (tmp-st.top()-1)*heights[tmp];
                    else
                        val += tmp*heights[tmp];
                    ans = max(ans, val);
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            int tmp = st.top();
            st.pop();
            int val = (heights.size()-tmp)*heights[tmp];
            if(!st.empty())
                val += (tmp-st.top()-1)*heights[tmp];
            else
                val += tmp*heights[tmp];
            ans = max(ans, val);
        }
        return ans;
    }
};