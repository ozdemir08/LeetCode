#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
 
 bool cmp(Interval a, Interval b){
     if(a.start != b.start)
        return a.start < b.start;
    return a.end > b.end;
 }
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> merged;
        Interval last;
        if(intervals.size() == 0)
            return merged;
        last = intervals[0];
        for(int i=1;i<intervals.size();i++)
            if(intervals[i].start <= last.end)
                last.end = max(last.end, intervals[i].end);
            else{
                merged.push_back(last);
                last = intervals[i];
            }
        merged.push_back(last);
        return merged;
    }
};

int main(){
    vector<Interval> v;
    for(int i=0;i<10;i++)
        v.push_back(Interval(i, i+2));
    Solution s;
    v = s.merge(v);
    for(int i=0;i<v.size();i++)
        cout << v[i].start << ' ' << v[i].end << endl;
}