#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// first -> height, second -> index
typedef pair<int,int> Height;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        set<int> limits;
        std::set<int>::iterator itlow,itup;

        vector<Height> sorted;
        for(int i=0;i<n;i++)
            sorted.push_back(make_pair(heights[i], i));

        // sort according to height
        sort(sorted.begin(), sorted.end());

        int res = 0;
        vector<int> toAdd;
        limits.insert(-1);
        limits.insert(n);

        for(int i=0;i<n;i++){
            int height = sorted[i].first;
            int index = sorted[i].second;

            // handling same heights
            if(!toAdd.empty() && heights[toAdd[0]] != height){
                for(int j=0;j<toAdd.size();j++)
                    limits.insert(toAdd[j]);

                toAdd.clear();
            }
            toAdd.push_back(index);

            itlow = limits.lower_bound(index);
            itup = limits.upper_bound(index);

            int left = *(--itlow), right = *itup;
            int area = (right - left - 1) * height;
            res = max(res, area);
        }
        
        return res;
    }
};

int main(){
    std::vector<int> v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(5);
    v.push_back(3);
    v.push_back(1);
    // v.push_back(2);
    // v.push_back(1);
    Solution s;
    cout << s.largestRectangleArea(v) << endl;



    // std::set<int> myset;
    // std::set<int>::iterator itlow,itup;

    // for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

    // itlow=myset.lower_bound (100);                //       ^
    // itlow--;
    // cout << *(--itlow) << endl;
    // itup=myset.upper_bound (60);                 //                   ^

}