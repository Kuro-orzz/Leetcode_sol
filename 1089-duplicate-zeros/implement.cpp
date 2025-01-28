class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(!arr[i]){
                arr.insert(arr.begin()+i, 0);
                i++;
            }
        }
        while(arr.size() > n)
            arr.pop_back();
    }
};