class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2;
        for(int x : nums1)
            mp1[x]++;
        for(int x : nums2)
            mp2[x]++;
        vector<int> ans;
        for(auto it : mp1){
            if(mp2.find(it.first) != mp2.end()){
                for(int i = 0; i < min(mp2[it.first], it.second); i++)
                    ans.push_back(it.first);
            }
        }
        return ans;
    }
};