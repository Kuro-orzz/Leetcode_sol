class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[arr[i]] = i;
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int cnt = 2;
                int val1 = arr[i], val2 = arr[j];
                while(mp.count(val1+val2)){
                    val2 += val1;
                    val1 = val2-val1;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        if(ans < 3) return 0;
        return ans;
    }
};