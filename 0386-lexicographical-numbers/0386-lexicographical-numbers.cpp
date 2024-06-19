class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        auto cmp = [&](int a, int b){
            string u = to_string(a), v = to_string(b);
            while(u.size() < v.size())
                u += '*';
            while(u.size() > v.size())
                v += '*';
            for(int i = 0; i < u.size(); i++){
                if(u[i] != v[i])
                    return u[i] < v[i];
            }
            return u < v;
        };
        sort(v.begin(), v.end(), cmp);
        return v;
    }
};