class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        for(int i = 0; i < operations.size(); i++)
            if(operations[i] == "C")
                ans.pop_back();
            else if(operations[i] == "D")
                ans.push_back(ans.back()*2);
            else if(operations[i] == "+")
                ans.push_back(ans[ans.size()-1]+ans[ans.size()-2]);
            else
                ans.push_back(stoi(operations[i]));
        int sum = 0;
        for(int i : ans)
            sum += i;
        return sum;
    }
};