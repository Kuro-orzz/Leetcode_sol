class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int p1 = 0, p2 = people.size()-1;
        int ans = 0;
        while(p1 <= p2){
            if(people[p1] + people[p2] <= limit)
                p1++, p2--;
            else
                p2--;
            ans++;
        }
        return ans;
    }
};