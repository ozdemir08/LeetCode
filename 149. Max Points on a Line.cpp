#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };

Point reff(0, 1);
bool cmp(Point a, Point b){
     return atan2(a.y - reff.y, a.x - reff.x) < atan2(b.y - reff.y, b.x - reff.x);
}

class Solution {
public:

    int maxPoints(vector<Point>& points) {
        vector<Point> originals;
        int result = 0;
        for(int i=0;i<points.size();i++)
             originals.push_back(points[i]);

         for(int i=0;i<originals.size();i++){
             bool marked[10000] = {};
             reff.x = originals[i].x;
             reff.y = originals[i].y;
             sort(points.begin(), points.end(), cmp);
             int samenumber = 0, current = 1;

             for(int j=0;j<points.size();j++)
                if(points[j].x == reff.x && points[j].y == reff.y){
                    samenumber++;
                    marked[j] = true;
                }
             result = max(result, samenumber);

            Point prev;
            bool prevFlag = true;
             for(int j=0;j<points.size();j++){
                 if(marked[j])
                    continue;
                if(prevFlag){
                    prev = points[j];
                    prevFlag = false;
                    continue;
                }
                 Point a = points[j];
                 if(atan2(a.y - reff.y, a.x - reff.x) != atan2(prev.y - reff.y, prev.x - reff.x)){
                     result = max(result, samenumber + current);
                     current = 1;
                 }
                 else
                     current++;

                 prev = points[j];
             }
             if(samenumber < points.size())
                 result = max(result, samenumber + current);
         }
         return result;
    }

};

int main(){
    int N;
    vector<Point> v;
    cin >> N;
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        Point a(x,y);
        v.push_back(a);
    }
    Solution solution;
    cout << solution.maxPoints(v) << endl;
}
