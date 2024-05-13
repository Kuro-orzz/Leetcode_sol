class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        stringstream s1(num1);
        string t1; getline(s1, t1, '+');
        string t2; getline(s1, t2, 'i');
        cout << t1 << endl << t2 << endl;
        stringstream s2(num2);
        string k1; getline(s2, k1, '+');
        string k2; getline(s2, k2, 'i');
        cout << k1 << endl << k2;
        string ans = "";
        int tmp1 = stoi(t1)*stoi(k1) - stoi(t2)*stoi(k2);
        int tmp2 = stoi(t1)*stoi(k2) + stoi(t2)*stoi(k1);
        ans = to_string(tmp1) + '+' + to_string(tmp2) + 'i';
        return ans;
    }
};