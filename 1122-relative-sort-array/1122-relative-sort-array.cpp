class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        for(int x : arr1)
            mp[x]++;
        int cnt = 0;
        vector<int> ans;
        for(int i = 0; i < arr2.size(); i++){
            while(mp[arr2[i]]){
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
        for(auto it : mp){
            if(it.second){
                for(int i = 0; i < it.second; i++)
                    ans.push_back(it.first);
            }
        }
        return ans;
    }
};