class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<tuple<int, int, char>> v;
        for(int i = 0; i < positions.size(); i++)
            v.push_back({positions[i], healths[i], directions[i]});
        auto cmp = [&](tuple<int, int, char> a, tuple<int, int, char> b){
            return get<0>(a) < get<0>(b);
        };
        sort(v.begin(), v.end(), cmp);
        stack<int> st;
        for(int i = 0; i < v.size(); i++){
            if(st.empty()) st.push(i);
            else if(get<2>(v[st.top()]) == 'R' && get<2>(v[i]) == 'L'){
                int ch = true;
                while(!st.empty() && get<2>(v[st.top()]) == 'R'){
                    if(get<1>(v[st.top()]) == get<1>(v[i])){
                        st.pop();
                        ch = false;
                        break;

                    }
                    else if(get<1>(v[st.top()]) < get<1>(v[i])){
                        get<1>(v[i])--;
                        st.pop();
                    }
                    else{
                        get<1>(v[st.top()])--;
                        ch = false;
                        break;
                    }
                }
                if(ch) st.push(i);
            } 
            else st.push(i);
        }
        unordered_map<int, int> mp;
        while(!st.empty()){
            mp[get<0>(v[st.top()])] = get<1>(v[st.top()]);
            st.pop();
        }
        vector<int> ans;
        for(int i = 0; i < positions.size(); i++){
            if(mp.find(positions[i]) != mp.end()){
                ans.push_back(mp[positions[i]]);
            }
        }
        return ans;
    }
};