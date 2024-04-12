class Solution {
public:
    void sortColors(vector<int>& nums) {
    	int n = nums.size();
        int zeroIndex = 0, twoIndex = n-1;

        for(int i=zeroIndex;i<=twoIndex;i++){
        	if(nums[i] == 0){
        		swap(nums[i], nums[zeroIndex]);
        		zeroIndex++;
        	}
        	else if(nums[i] == 2){
        		swap(nums[i], nums[twoIndex]);
                twoIndex--;
                i--;
        	}
        }
    }
};