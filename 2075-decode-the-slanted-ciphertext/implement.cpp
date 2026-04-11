class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (!n) return "";
        int cols = n / rows;
        string ans = "";
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                if (j * cols + i + j >= n) break;
                ans += encodedText[j * cols + i + j];
            }
        }
        while (ans.back() == ' ') ans.pop_back();
        return ans;
    }
};