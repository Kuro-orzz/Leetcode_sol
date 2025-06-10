#define pii pair<int, int>
struct cmp{
    bool operator()(pii a, pii b){
        if(a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }
};
class Solution {
public:
    string clearStars(string s) {
        unordered_set<int> rm;
        priority_queue<pii, vector<pii>, cmp> pq; 
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*'){
                rm.insert(pq.top().second);
                rm.insert(i);
                pq.pop();
            }
            else
                pq.push({s[i], i});
        }
        string ans = "";
        for(int i = 0; i < s.size(); i++)
            if(rm.find(i) == rm.end())
                ans += s[i];
        return ans;
    }
};