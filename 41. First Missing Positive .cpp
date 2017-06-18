#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int ind = nums[i] - 1;
        	if(nums[i] == i+1 || ind < 0 || ind >= n || nums[ind] == nums[i]) continue;
            int x = nums[ind];
            nums[ind] = nums[i];
            nums[i--] = x;
        }
        for(int i=0;i<n;i++)
            if(nums[i] != i+1)
                return i+1;
        return n+1;
    }
};

int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(-1);
	v.push_back(2);
	v.push_back(-4);
	v.push_back(10);
	v.push_back(1);
	Solution s;
	cout << s.firstMissingPositive(v) << endl;
}