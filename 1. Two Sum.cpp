class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> M;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            if(M[target - nums[i]]){
                result.push_back(M[target - nums[i]] - 1);
                result.push_back(i);
            }
            else
                M[nums[i]] = i + 1;
        }
        return result;
    }
};