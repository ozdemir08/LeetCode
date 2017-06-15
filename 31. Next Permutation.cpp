class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int x;
    	for(int i=nums.size()-1;i>0;i--){
    		if(nums[i] > nums[i-1]){
    			x = nums[i-1];
    			sort(nums.begin()+i-1, nums.end());
    			for(int j=nums.size()-1;j>=i-1;j--){
    				if(nums[j] == x){
    					while(j>=i-1){
    						int t = nums[j];
    						nums[j] = nums[j+1];
    						nums[j+1] = t;
    						j--;
    					}
    				return;		
    				}
    			}
    		}
    	}
    	sort(nums.begin(), nums.end());
    }
    
};