#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	vector<int> dp(amount+1, amount+1);
    	dp[0] = 0;
    	int n = coins.size();
    	for(int i=0;i<n;i++){
    		int coin = coins[i];
            if(coin <= amount)
    			dp[coin] = 1; 
    		for(int j=1;j<=amount;j++)
    			if(coin <= amount && dp[j] != amount+1 && j + coin <= amount)
    				dp[j + coin] = min(dp[j + coin], dp[j] + 1);  		
    	}

    	int res = (dp[amount] == amount+1) ? -1 : dp[amount];
    	return res;
    }
};

int main(){
	Solution s;
	vector<int> v;
	v.push_back(2147483647);
	cout << s.coinChange(v, 2) << endl;

	return 0;
}