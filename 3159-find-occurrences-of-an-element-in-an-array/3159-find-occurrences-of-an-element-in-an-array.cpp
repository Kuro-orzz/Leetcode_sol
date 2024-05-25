class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> v;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == x)
                v.push_back(i);
        }
        vector<int> ans;
        for(int x : queries){
            if(x > v.size())
                ans.push_back(-1);
            else{
                ans.push_back(v[x-1]);
            }
        }
        return ans;
    }
};