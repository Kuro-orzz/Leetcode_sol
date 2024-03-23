class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        for(int x : nums1)
            s1.insert(x);
        unordered_set<int> s2;
        for(int x : nums2)
            s2.insert(x);
        vector<int> ans;
        for(int i : s2){
            if(s1.find(i) != s1.end())
                ans.push_back(i);
        }
        return ans;
    }
};