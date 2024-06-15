#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        pii p[n];
        for(int i = 0; i < n; i++)
            p[i] = {capital[i], profits[i]};
        sort(p, p+n);
        priority_queue<int> pq;
        int ans = w;
        int i = 0;
        while(k){
            if(i < n && p[i].fi <= ans){
                pq.push(p[i].se);
                i++;
            }
            else{
                if(!pq.empty()){
                    ans += pq.top();
                    pq.pop();
                }
                k--;
            }
        }
        return ans;
    }
};