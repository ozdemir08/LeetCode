        class Solution {
private:
    static bool cmp(const vector<int>& c1, const vector<int>& c2){
        // 0 -> time, 1 -> end
        return c1[1] < c2[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        int N = courses.size();
        
        multiset<int> lengths;
        int time = 0;
        for(int i=0;i<N;i++){
            int t = courses[i][0], d = courses[i][1];
            if(time + t <= d){
                lengths.insert(t);
                time += t;
            }
            else{
                lengths.insert(t);
                auto it = --lengths.end();
                time += t - (*it);
                lengths.erase(it);
            }
        }
        return lengths.size();
    }
};