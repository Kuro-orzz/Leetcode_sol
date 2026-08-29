class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int start1 = stoi(event1[0].substr(0, 2)) * 60 + stoi(event1[0].substr(3));
        int end1 = stoi(event1[1].substr(0, 2)) * 60 + stoi(event1[1].substr(3));
        int start2 = stoi(event2[0].substr(0, 2)) * 60 + stoi(event2[0].substr(3));
        int end2 = stoi(event2[1].substr(0, 2)) * 60 + stoi(event2[1].substr(3));
        if (start1 > start2) {
            swap(start1, start2);
            swap(end1, end2);
        }
        if (end1 >= start2) return true;
        return false;
    }
};