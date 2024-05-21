class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        int sum = 0;
        vector<int> v;
        vector<int> negative;
        for(int i : satisfaction)
            if(i >= 0){
                v.push_back(i);
                sum += i;
            }
            else{
                negative.push_back(i);
            }
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 0; i < v.size(); i++)
            ans += v[i]*(i+1);
        sort(negative.begin(), negative.end(), greater<int>());
        pair<int, int> inc = {0, 0};
        for(int i = 1; i <= negative.size(); i++){
            int tmp = 0;
            for(int j = i; j >= 1; j--)
                tmp += negative[j-1]*(i-j+1);
            if(inc.first < sum*i + tmp)
                inc = {sum*i+tmp, i};
        }
        return ans+inc.first;
    }
};