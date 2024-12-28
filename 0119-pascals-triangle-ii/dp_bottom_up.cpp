class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> make(rowIndex+1);
        for(int i = 0; i <= rowIndex; i++)
            for(int j = 0; j < i+1; j++)
                if(j == 0 || j == i)
                    make[i].push_back(1);
                else
                    make[i].push_back(make[i-1][j-1]+make[i-1][j]);
        return make[rowIndex];
    }
};