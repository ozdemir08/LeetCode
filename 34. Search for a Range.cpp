class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int mn = -1, mx = -1;
        while(l<=r){
            int m = (l+r) / 2;
            if(nums[m] == target){
                mn = m;
                r = m - 1;
            }
            else if(nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        
        l = 0; r = nums.size() - 1;
        while(l<=r){
            int m = (l+r) / 2;
            if(nums[m] == target){
                mx = m;
                l = m + 1;
            }
            else if(nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        vector<int> v;
        v.push_back(mn);
        v.push_back(mx);
        return v;
    }
};