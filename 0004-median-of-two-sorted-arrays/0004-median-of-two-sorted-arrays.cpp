class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        vector<int> a;
        int cnt1 = 0;
        int cnt2 = 0;
        while(cnt1 < nums1.size() && cnt2 < nums2.size()){
            if(nums1[cnt1] < nums2[cnt2]){
                a.push_back(nums1[cnt1]);
                cnt1++;
            }
            else{
                a.push_back(nums2[cnt2]);
                cnt2++;
            }
        }
        while(cnt1 < nums1.size()){
            a.push_back(nums1[cnt1]);
            cnt1++;
        }
        while(cnt2 < nums2.size()){
            a.push_back(nums2[cnt2]);
            cnt2++;
        }
        if(a.size()%2==0)
            return (a[a.size()/2-1]+a[a.size()/2])/2.0;
        else
            return a[a.size()/2];
    }
};