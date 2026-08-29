#define all(x) (x).begin(),(x).end()
#define unique(x) x.erase(unique(all(x)), x.end())

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp = arr;
        sort(all(temp));
        unique(temp);
        map<int, int> mp;
        for (int i = 0; i < temp.size(); i++) {
            mp[temp[i]] = i+1;
        }
        vector<int> ans(n);
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};