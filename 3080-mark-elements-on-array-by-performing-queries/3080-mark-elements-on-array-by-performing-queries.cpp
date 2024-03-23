class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        map<int, vector<int>> mp;
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            mp[nums[i]].push_back(i);
        }
        for(auto &it : mp)
            reverse(it.second.begin(), it.second.end());
        bool marked[nums.size()];
        memset(marked, false, sizeof(marked));
        vector<long long> ans;
        int cntMarked = 0;
        for(int i = 0; i < queries.size(); i++){
            if(cntMarked < nums.size()){
                if(!marked[queries[i][0]]){ //&& mp.find(queries[i][0]) != mp.end()){
                    marked[queries[i][0]] = true;
                    cntMarked++;
                    sum -= nums[queries[i][0]];
                }
                while(queries[i][1] && mp.size()){
                    auto it = mp.begin();
                    int cnt = 0;
                    while(cnt < queries[i][1] && (*it).second.size()){
                        if(!marked[(*it).second.back()]){
                            cnt++;
                            marked[(*it).second.back()] = true;
                            cntMarked++;
                        }
                        (*it).second.pop_back();                        
                    }
                    sum -= (*it).first * 1ll*cnt;
                    queries[i][1] -= cnt;
                    if((*it).second.size() == 0)
                        mp.erase(it);
                }
            }
            ans.push_back(sum);            
        }
        return ans;
    }
};