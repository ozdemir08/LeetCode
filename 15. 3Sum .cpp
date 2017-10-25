class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	vector< vector<int> > res;
    	int N = nums.size();

    	for(int i=0;i<N;i++){
    		if(i > 0 && nums[i-1] == nums[i])
    			continue;
    		int target = -nums[i];
    		int l = i+1, r = N-1;

    		// two sum problem
    		while(l < r){
    			int twoSum = nums[l] + nums[r];
    			if(twoSum < target)
    				l++;
    			else if(twoSum > target)
    				r--;
    			else{
    				// create solution tuple
    				vector<int> subres;
    				subres.push_back(nums[i]);
    				subres.push_back(nums[l]);
    				subres.push_back(nums[r]);
    				res.push_back(subres);

    				// increment l to prevent getting same solution
    				while(subres[1] == nums[l]) 
    					l++;
	    		}
			}
    	}
        return res;
    }
    
};