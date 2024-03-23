class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int i : arr)
            mp[i]++;
        int a[mp.size()];
        int cnt = 0;
        for(auto it : mp){
            a[cnt]=  it.second;
            cnt++;
        }
        sort(a, a+cnt);
        for(int i = 0; i < cnt; i++){
            k -= a[i];
            if(k < 0)
                return cnt-i;
        }
        return 0;
    }
};