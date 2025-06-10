class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size()-1;
        int ans = letters.size();
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (letters[mid] > target) {
                ans = mid;
                r = mid - 1;
            } else { 
                l = mid + 1;
            }
        }
        if (ans == letters.size()) {
            return letters[0];
        }
        return letters[ans];
    }
};