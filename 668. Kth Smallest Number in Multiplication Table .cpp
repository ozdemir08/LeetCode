class Solution {
private:
	int countSmaller(int m, int n, int target){
		int count = 0;
		for(int i=1;i<=n;i++){
			if(m*i > target){
				m--;
				i--;
			}
			else
				count += m;
		}
		return count;
	}

public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m*n;
        while(low <= high){
        	int mid = (low + high) / 2;
        	int count = countSmaller(m, n, mid);
        	if(count < k)
        		low = mid + 1;
        	else
        		high = mid - 1;
        }
        return low;
    }
};