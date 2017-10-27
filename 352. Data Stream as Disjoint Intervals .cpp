/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
private:
    
public:
    /** Initialize your data structure here. */
    // [beg, end]
    map<int,int> intervals;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if(intervals.empty()){
            intervals[val] = val;
            return;
        }

        // if any interval starts with this val exists, do not do anything.
        if(intervals.find(val) != intervals.end())
            return;

        auto next = intervals.upper_bound(val);

        // put just before next
        intervals[val] = val;
        auto cur = prev(next);
        
        // check if new interval can merge with previous
        if(cur != intervals.begin()){
            auto pre = prev(cur);
            int firstEnd = pre -> second;
            int secondFirst = cur -> first;
            if(firstEnd >= secondFirst - 1){
                pre -> second = max (firstEnd, cur -> second);
                intervals.erase(cur);
                cur = pre;
            }
        }

        // check if next interval can merge with current
        if(next != intervals.end()){
            int firstEnd = cur -> second;
            int secondFirst = next -> first;
            if(firstEnd >= secondFirst - 1){
                cur -> second = max(firstEnd, next -> second);
                intervals.erase(next);
            }
        }
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> res;
        for(auto& it : intervals){
            int start = it.first;
            int end = it.second;
            res.push_back(Interval(start, end));
        }
        return res;
    }       
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */