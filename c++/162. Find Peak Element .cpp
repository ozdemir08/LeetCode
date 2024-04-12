class Solution {
private:
    int findPeakElement(int beg, int end, vector<int>& nums) {
        if(beg > end)
            return -1;
        int mid = (beg + end) / 2;
        if((!mid || nums[mid] > nums[mid-1]) && (mid == nums.size() -1 || nums[mid] > nums[mid+1]))
            return mid;
        int res = findPeakElement(beg, mid-1, nums);
        if(res == -1)
            res = findPeakElement(mid+1, end, nums);
        return res;
    }
public:
    int findPeakElement(vector<int>& nums) {
        return findPeakElement(0, nums.size()-1, nums);
    }
};