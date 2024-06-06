class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        for(int i = 0; i < hand.size(); i++)
            mp[hand[i]]++;
        for(auto &it : mp){
            if(it.second < 0)
                return false;
            while(it.second > 0){
                for(int i = it.first; i < it.first+groupSize; i++)
                    mp[i]--;
            }
            // cout << it.first << " " << it.second << endl;
        } 
        for(auto &it : mp)
            if(it.second != 0)
                return false;
        return true;
    }
};