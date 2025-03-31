#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    static bool cmp1(pii a, pii b){
        return a.fi + a.se < b.fi + b.se;
    }

    static bool cmp2(pii a, pii b){
        return a.fi + a.se > b.fi + b.se;
    }

    long long putMarbles(vector<int>& weights, int k) {
        vector<pii> v;
        for(int i = 1; i < weights.size(); i++)
            v.push_back({weights[i-1], weights[i]});
        sort(v.begin(), v.end(), cmp1);
        long long mn = weights[0] + weights.back();
        for(int i = 0; i < k-1; i++)
            mn += v[i].fi + v[i].se;
        sort(v.begin(), v.end(), cmp2);
        long long mx = weights[0] + weights.back(); 
        for(int i = 0; i < k-1; i++)
            mx += v[i].fi + v[i].se;
        return mx-mn;
    }
};