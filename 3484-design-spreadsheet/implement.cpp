class Spreadsheet {
public:
    map<string, int> mp;

    Spreadsheet(int rows) {

    }
    
    void setCell(string cell, int value) {
        mp[cell] = value;
    }
    
    void resetCell(string cell) {
        mp[cell] = 0;
    }
    
    int getValue(string formula) {
        int pos = 0;
        while(formula[pos] != '+') pos++;
        string s1 = formula.substr(1, pos-1);
        string s2 = formula.substr(pos+1);
        int ans = 0;
        if(s1[0] >= '0' && s1[0] <= '9')
            ans += stoi(s1);
        else ans += mp[s1];
        if(s2[0] >= '0' && s2[0] <= '9')
            ans += stoi(s2);
        else ans += mp[s2];
        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */