#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>

using namespace std;

/**
    Solution 2 O(N) time complexity
**/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> indices;
        int res = 0;
        int n = heights.size();
        for(int i=0;i<=n;i++){
            int h = (i == n ? 0 : heights[i]);
            if(indices.empty() || heights[indices.top()] <= h){
                indices.push(i);
            }
            else{
                int last = indices.top();
                indices.pop();

                int interval = 0;
                if(indices.empty())
                    interval = i;
                else
                    interval = i - indices.top() - 1;

                int area = interval * heights[last];
                res = max(res, area);
                i--;
            }
        }
        return res;
    }
};

/**
    Solution 1 O(N log(N)) time complexity
**/
// first -> height, second -> index
typedef pair<int,int> Height;

class Solution2 {
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
    v.push_back(0);
    v.push_back(2);
    Solution s;
    cout << s.largestRectangleArea(v) << endl;

}