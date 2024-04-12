#include <iostream>
#include <vector>

using namespace std;

class Number{
public:
	int val, index, smallerNums;
	Number(int v, int i){
		val = v; 
		index = i;
		smallerNums = 0;
	}
};

class Solution {
private:
	void merge(vector<Number>& nums, int left, int right){
		if(left == right)
			return;
		int mid = (left+right)/2;

		// sort two halves
		merge(nums, left, mid);
		merge(nums, mid+1, right);

		int n = right - left + 1;
		int beg1 = left, beg2 = mid+1;

		// merge sorted two array
		vector<Number> merged(N+M, Number(0,0));
		for(int i=0;i<n;i++){
			if(beg1 == mid+1 || (beg2 <= right && nums[beg1].val > nums[beg2].val)){
				merged[i] = nums[beg2];
				beg2++;
			}
			else{
                // beg1 is its position in left half and i + left is its new position in whole. Difference is # of smaller nums
				nums[beg1].smallerNums += i + left - beg1;
				merged[i] = nums[beg1];
				beg1++;
			}
		}

		for(int i=0;i<n;i++){
			nums[i+left] = merged[i];
			cout << merged[i].val << ' ' << merged[i].smallerNums << endl;
		}
	}
public:
    vector<int> countSmaller(vector<int>& nums) {
    	int n = nums.size();
    	vector<Number> numbers;

    	// convert to vector<Number>
    	for(int i=0;i<n;i++)
    		numbers.push_back(Number(nums[i], i));

        // merge
    	merge(numbers, 0, n-1);

    	// convert back to vector<int>
    	vector<int> res(n, 0);
    	for(int i=0;i<n;i++){
    		int ind = numbers[i].index;
    		int smallerNums = numbers[i].smallerNums;
    		res[ind] = smallerNums;
	    }
	    return res;
	}
};

int main(){
	Solution s;
	std::vector<int> v;
	v.push_back(5);
	v.push_back(2);
	v.push_back(6);
	v.push_back(1);
	v.push_back(0);
	v.push_back(8);
	v.push_back(2);
	std::vector<int> res = s.countSmaller(v);
	for(int i=0;i<res.size();i++)
		cout << res[i] << ' ' ;
	cout << endl;
}