class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        int t = 0;
        int v = 0;
        for(int i = 0; i < customers.size(); i++){
            if(!grumpy[i])
                ans += customers[i];
            else
                t += customers[i];
            if(i >= minutes-1){
                v = max(v, t);
                if(grumpy[i-minutes+1])
                    t -= customers[i-minutes+1];
            }
        }
        return ans+v;
    }
};