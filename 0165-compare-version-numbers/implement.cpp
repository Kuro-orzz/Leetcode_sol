class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int m = version2.size();
        int p1 = 0, p2 = 0;
        while (p1 < n || p2 < m) {
            if (p1 < n && version1[p1] == '.') p1++;
            if (p2 < m && version2[p2] == '.') p2++;
            int ver1 = 0, ver2 = 0;
            while (p1 < n && version1[p1] != '.') {
                ver1 = ver1 * 10 + (version1[p1++] - '0');
            }
            while (p2 < m && version2[p2] != '.') {
                ver2 = ver2 * 10 + (version2[p2++] - '0');
            }
            if (ver1 < ver2) return -1;
            else if (ver1 > ver2) return 1;
        }
        return 0;
    }
};