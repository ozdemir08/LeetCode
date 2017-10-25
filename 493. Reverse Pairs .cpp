#define ll long long

class Solution {
private:
	void merge(vector<int>& nums, int left, int right, int &res){
		if(left >= right)
			return;

		int mid = (left + right) / 2;

		// sort halves
		merge(nums, left, mid, res);
		merge(nums, mid+1, right, res);

		// merge to merged
		int n = right - left + 1;
		vector<int> merged(n, 0);
		int lIndex = left, rIndex = mid+1;

        // count inverses
		int l = left, r = mid+1;
		for(int i=left;i<=mid;i++){
			while(r <= right && (ll)2*nums[r] < nums[i]) r++;
			res += r - mid - 1;
		}

        // merge halves to merged
		for(int i=0;i<n;i++)
			if(lIndex > mid || (rIndex <= right && nums[lIndex] >= nums[rIndex])){
				merged[i] = nums[rIndex];
				rIndex++;
			}
			else{
                merged[i] = nums[lIndex];
                lIndex++;
			}

		// merged to original
		for(int i=0;i<n;i++)
			nums[left + i] = merged[i];

	}
public:
    int reversePairs(vector<int>& nums) {
    	int n = nums.size();
    	int res = 0;
    	merge(nums, 0, n-1, res);
    	return res;    
    }
};