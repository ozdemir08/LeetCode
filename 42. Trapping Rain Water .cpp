#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
    	int N = height.size();
        vector<int> left(N, 0), right(N, 0);
        int leftLimit = 0, rightLimit = 0;
        for(int i=0;i<N;i++){
        	leftLimit = max(leftLimit, height[i]);
        	left[i] = leftLimit;
        }
        for(int i=N-1;i>=0;i--){
        	rightLimit = max(rightLimit, height[i]);
        	right[i] = rightLimit;
        }

        int res = 0;
        for(int i=0;i<N;i++)
        	res += min(left[i], right[i]) - height[i];
        return res;
    }
    
};

int main(){
	Solution s;
	std::vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(2);
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	cout << s.trap(v) << endl;
}