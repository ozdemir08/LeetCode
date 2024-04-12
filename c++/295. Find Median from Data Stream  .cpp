#include <iostream>
#include <queue>
#include <vector>
#include <functional> 
#include <algorithm>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> smallQ, bigQ;
    
    void addNum(int num) {
    	if(smallQ.empty() || num <= smallQ.top()){
   			smallQ.push(num);
   			if(smallQ.size() > bigQ.size() + 1){
   				int x = smallQ.top();
   				smallQ.pop();

   				bigQ.push(-x);
   			}
    	}
    	else{
			bigQ.push(-num);
			if(bigQ.size() > smallQ.size()){
				int x = -bigQ.top();
				bigQ.pop();

				smallQ.push(x);
    		}
		}
    }
    
    double findMedian() {

    	if(smallQ.size() > bigQ.size())
    		return smallQ.top();

        return (smallQ.top() - bigQ.top()) / 2.0;
    }

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

int main(){
	MedianFinder obj;
	obj.addNum(1);
	cout << obj.findMedian() << endl;
	obj.addNum(2);
	cout << obj.findMedian() << endl;
	obj.addNum(3);
	cout << obj.findMedian() << endl;
	obj.addNum(-4);
	cout << obj.findMedian() << endl;
	obj.addNum(-5);
	cout << obj.findMedian() << endl;
}