class Solution {
public:
    int minimumPushes(string word) {
        set<char> s;
        for (char &c : word) {
            s.insert(c);
        }
        int k = s.size();
        if (k <= 8) return k;
        else if (k <= 16) return (k-8) * 2 + 8;
        else if (k <= 24) return (k-16) * 3 + 8 * 2 + 8;
        else return (k-24) * 4 + 8 * 3 + 8 * 2 + 8;
    }
};