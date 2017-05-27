#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN)
            return 0;
        bool sign = (x >= 0);
        x = x * (sign? 1 : -1);
        long long rev = 0;
        while(x){
            rev = rev*10 + x % 10;
            x /= 10;
        }
        if(rev > INT_MAX)
            return 0;
        else
            return rev * (sign? 1 : -1);
    }
};

int main(){
    Solution s;
    int input;
    cin >> input;
    cout << s.reverse(input) << endl;
}