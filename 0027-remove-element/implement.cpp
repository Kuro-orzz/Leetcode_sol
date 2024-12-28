class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = 0;
        vector<int> tmp;
        for(int i : nums)
            if(i != val){
                ans++;
                tmp.push_back(i);
            }
        for(int i = 0; i < ans; i++)
            nums[i] = tmp[i];
        return ans;
    }
};