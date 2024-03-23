class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(int i = 0; i < tasks.size(); i++)
            mp[tasks[i]]++;
        priority_queue<pair<int, int>> pq;
        for(auto it : mp)
            pq.push({it.second, INT_MAX});
        long long ans = 0;
        while(!pq.empty()){
            vector<pair<int,int>> tmp;
            for (int i = 0; i <= n; i++) {
                if (pq.size() == 0) break;
                tmp.push_back(pq.top());
                pq.pop();
            }
            for (int i = 0; i < tmp.size(); i++) {
                ans++;
                tmp[i].second *= -1;
                if (ans - tmp[i].second <= n) 
                    ans = tmp[i].second + n + 1;
                if (tmp[i].first == 1) continue;
                pq.push({tmp[i].first - 1, -ans});
            }
        }
        return ans;
    }
};