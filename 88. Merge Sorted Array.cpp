class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int N = m + n;
        while(N){
            if(n <= 0 || (m > 0 && nums1[m-1] > nums2[n-1]))
                nums1[--N] = nums1[--m];
            else
                nums1[--N] = nums2[--n];
        }
    }
};