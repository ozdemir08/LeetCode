#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid;
        while(l<=r){
            mid = (l+r) / 2;
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] >= nums[l]){
                if(nums[mid]>target && nums[l]<=target)
                    r = mid-1;
                else
                    l = mid+1;
            }
            else{
                if(nums[mid]<target && nums[r]>=target)
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v;
    v.push_back(3);
    v.push_back(1);
    // for(int i=5;i<10;i++)
    //     v.push_back(i);
    // for(int i=0;i<5;i++)
    //     v.push_back(i);
    cout << s.search(v, 1) << endl;
    return 0;
}