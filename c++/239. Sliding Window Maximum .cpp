#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque< int > q;
        vector<int> res;
        for(int i=0;i<nums.size();i++){

        	if(!q.empty() && i - q.front() >= k)
        		q.pop_front();

        	while(!q.empty() && nums[q.back()]<=nums[i])
        		q.pop_back();

        	q.push_back(i);
        	if(i >= k-1)
        		res.push_back(nums[q.front()]);
        }
        return res;
	}
};

int main(){
	std::vector<int> v;
	v.push_back(5);
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(6);
	Solution s;
	std::vector<int> res = s.maxSlidingWindow(v, 3);
	for(int i=0;i<res.size();i++)
		cout << res[i] << ' ';
	cout << endl;
}