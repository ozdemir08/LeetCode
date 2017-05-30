#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend_, int divisor_) {
        if(dividend_ == INT_MIN && divisor_ == -1)
            return INT_MAX;

        int sign = ((dividend_ >=0 && divisor_ >=0) || (dividend_ <=0 && divisor_ <=0) ? 1 : -1);
        long long dividend = dividend_, divisor = divisor_;
        dividend = abs(dividend);
        divisor = abs(divisor);

        if(divisor == 1)
            return (sign == 1 ? dividend : -dividend);

        long long divisors[32] = {1, divisor}, pow[32] = {0, 1};
        int i;
        for(i=2;i<32 && divisors[i-1]<INT_MAX;i++)
            for(int j=0;j<divisor;j++){
                divisors[i] += divisors[i-1];
                if(divisors[i] > INT_MAX)
                    break;
            }

        int res = 0;
        for(i--;i>0;i--)
            while(dividend >= divisors[i]){
                res += divisors[i-1];
                dividend -= divisors[i];
            }
        return (sign == 1 ? res : -res);
    }
};

int main(){
    Solution s;
    int a, b;
    cin >> a >> b;
    cout << s.divide(a, b) << endl;
}