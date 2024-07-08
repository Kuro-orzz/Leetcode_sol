class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int> dq;
        for(int i = 1; i <= n; i++)
            dq.push_back(i);
        int cnt = 0;
        while(dq.size() > 1){
            if(cnt < k-1){
                cnt++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else{
                cnt = 0;
                dq.pop_front();
            }
        }
        return dq.front();
    }
};