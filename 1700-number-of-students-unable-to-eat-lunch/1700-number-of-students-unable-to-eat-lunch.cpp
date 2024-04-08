class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int p = 0, cnt = 0;
        queue<int> q;
        for(int i = 0; i < students.size(); i++)
            q.push(students[i]);
        while(p < sandwiches.size() && cnt < sandwiches.size()-p){
            if(q.front() == sandwiches[p]){
                q.pop();
                p++;
                cnt = 0;
            }
            else{
                cnt++;
                q.push(q.front());
                q.pop();
            }
        }
        return q.size();
    }
};