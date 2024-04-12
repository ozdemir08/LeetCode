#include <iostream>

using namespace std;

class Solution {
public:

    double myPow(double x, int n) {
    	if(n == 0) return 1;
    	double subres = myPow(x, n/2);
    	if(n % 2 == 0)
    		return subres * subres;
    	if(n > 0)
    		return subres * subres * x;
    	return subres * subres / x;
    }

};

int main(){
	Solution s;
	cout << s.myPow(34.00515, -3) << endl;
}