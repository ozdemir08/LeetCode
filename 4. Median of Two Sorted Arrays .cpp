class Solution {
private:
	int findKthElement(vector<int>& nums1, int beg1, vector<int>& nums2, int beg2, int k){
		int m = nums1.size() - beg1, n = nums2.size() - beg2;
		if(m < n)
			return findKthElement(nums2, beg2, nums1, beg1, k);
		if(!n)
			return nums1[beg1+k-1];
		if(k == 1)
			return min(nums1[beg1], nums2[beg2]);

		int i = beg1 + min(m, k/2);
		int j = beg2 + min(n, k/2);
		if(nums1[i-1] > nums2[j-1])
			return findKthElement(nums1, beg1, nums2, j, k-j+beg2);
		else
			return findKthElement(nums1, i, nums2, beg2, k-i+beg1);
	}

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int m = nums1.size(), n = nums2.size();
        int m1 = (n+m+1)/2, m2 = (n+m+2)/2;
        
        int res1 = findKthElement(nums1, 0, nums2, 0, m1);
        int res2 = findKthElement(nums1, 0, nums2, 0, m2);
        return (res1 + res2) / 2.0;
    }
};