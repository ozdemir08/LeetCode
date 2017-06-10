class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0, pos = 0;
        while(pos <= maxReachable && pos<nums.size()){
            maxReachable = max(maxReachable, pos + nums[pos]);
            pos++;
        }
        
        return maxReachable >= nums.size() - 1;
    }
};