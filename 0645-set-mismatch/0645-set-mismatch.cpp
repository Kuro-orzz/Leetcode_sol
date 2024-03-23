class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++){
            if(st.find(nums[i]) != st.end())
                ans.push_back(nums[i]);
            st.insert(nums[i]);
        }
        for(int i = 1; i <= nums.size(); i++)
            if(st.find(i) == st.end()){
                ans.push_back(i);
                break;
            }
        return ans;
    }
};