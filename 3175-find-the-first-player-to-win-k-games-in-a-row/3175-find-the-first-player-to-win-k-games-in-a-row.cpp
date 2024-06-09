class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        vector<int> win(n, 0);
        queue<int> q;
        for(int i = 1; i < n; i++)
            q.push(i);
        bool check = true;
        int t = 0;
        int cnt = 0;
        while(check){
            if(skills[t] > skills[q.front()])
                q.push(q.front());
            else{
                q.push(t);
                t = q.front();
            }
            q.pop();
            win[t]++;
            if(win[t] == k)
                check = false;
            if(cnt > n)
                break;
            cnt++;
        }
        if(win[t] == k)
            return t;
        for(int i = 0; i < n; i++){
            if(skills[i] > skills[t])
                t = i;
        }
        return t;
    }
};