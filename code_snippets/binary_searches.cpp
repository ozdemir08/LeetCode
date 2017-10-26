/**
	Binary search in an array which contains duplicates.
**/


// find leftmost target
// e.g. nums => 1 2 3 3 3 4 5 6 7, target => 3
// 		return 2
int binary_search(vector<int>& nums, int target){
	int n = nums.size();
	int left = 0, right = n - 1;

	// carry right to the greatest number which is less than target.
	while(left <= right){
		int mid = (left + right) / 2;
		if(nums[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	// when we are here, right is at the index of greatest number
	// which is less than target and since left is at the next, 
	// it is at the first target's index
	return left;
}


// find rightmost target
// e.g. nums => 1 2 3 3 3 4 5 6 7, target => 3
// 		return 4  
int binary_search(vector<int>& nums, int target){
	while(left <= right){
		int mid = (left + right) / 2;
		// carry left to the smallest number which is greater than target.
		if(nums[mid] <= target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	// when we are here, left is at the index of smallest number
	// which is greater than target and since right is at the next, 
	// it is at the first target's index
	return right;
}