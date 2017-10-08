class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	int res = 0;
  		unordered_map<int, bool> numbers, prev;

  		for(int i=0;i<nums.size();i++)
  			numbers[nums[i]] = true;

  		for(int i=0;i<nums.size();i++){
  			int current = nums[i], size = 1;
  			
  			if(!numbers[current - 1]){
	  			while(numbers[current + size])
	  				size++;
	  			res = max(res, size);
			}
		}
		return res;
  	}
};