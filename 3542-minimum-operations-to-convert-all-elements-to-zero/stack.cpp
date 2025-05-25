class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int ans = 0;
        for (int x : nums) {
            while (!st.empty() && st.top() > x) st.pop(), ans++;
            if (x && (st.empty() || st.top() < x)) st.push(x);
        }
        return ans + st.size();
    }
};