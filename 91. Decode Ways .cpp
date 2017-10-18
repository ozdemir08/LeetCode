#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        
        int n = s.size();
        std::vector<int> DP(n+1, 0);
        DP[n] = 1;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '0')
                continue;
            DP[i] = DP[i+1];
            if(i<n-1){
                int num = 10*(s[i]-'0') + s[i+1] - '0';
                if(num <= 26)
                    DP[i] += DP[i+2];
            }
        }
        return DP[0];
    }
};

int main(){
    Solution s;
    // I missed "00"
    cout << s.numDecodings("00") << endl;
    // I missed "00"
    cout << s.numDecodings("120") << endl;
    cout << s.numDecodings("130") << endl;
    cout << s.numDecodings("27") << endl;
    cout << s.numDecodings("260") << endl;
    cout << s.numDecodings("261") << endl;
}