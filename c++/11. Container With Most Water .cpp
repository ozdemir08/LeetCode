#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
  		int left = 0, right = height.size() - 1, maxArea = 0;  		
  		while(left != right){
  			maxArea = max(maxArea, (right - left) * min(height[left], height[right]));
  			if(height[right] > height[left])
  				left++;
  			else
  				right++;
  		}	      
		return maxArea;
    }
};

int main(){

}