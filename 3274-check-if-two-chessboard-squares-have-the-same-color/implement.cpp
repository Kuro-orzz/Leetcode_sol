class Solution {
public:
    bool checkColor(string coordinates) {
        int a = coordinates[0]-'a'+1;
        int b = coordinates[1]-'0';
        if(a % 2 == 0 && b % 2 != 0)
            return true;
        else if(a % 2 != 0 && b % 2 == 0)
            return true;
        return false;
    }

    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        if(checkColor(coordinate1) == checkColor(coordinate2))
            return true;
        return false;
    }
};