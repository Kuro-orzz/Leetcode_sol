class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> ans(deck.size());
        queue<int> q;
        for(int i = 0; i < deck.size(); i++)
            q.push(i);
        sort(deck.begin(), deck.end());
        bool skip = false;
        int cnt = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                if(!skip){
                    ans[q.front()] = deck[cnt];
                    q.pop();
                    cnt++;
                    skip = true;
                }
                else{
                    q.push(q.front());
                    q.pop();
                    skip = false;
                }
            }
        }
        return ans;
    }
};