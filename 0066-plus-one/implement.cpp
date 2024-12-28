class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1] != 9){
            digits[n-1]++;
            return digits;
        }
        else{
            while(n && digits[n-1] == 9){
                digits[n-1] = 0;
                n--;
            }
            if(!n)
                digits.insert(digits.begin(), 1);
            else
                digits[n-1]++;
        }
        return digits;
    }
};