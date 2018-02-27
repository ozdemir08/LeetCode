#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	int index(int i){
		return (i+3) % 3;
	}
	const static int MOD = 1000000007;

public:
    int numTilings(int N) {
    	// base cases
    	if(N < 3)
    		return N;

		vector<int> f(N+1, 0);
        f[0] = f[1] = 1;
        f[2] = 2;

        long long prev = 0;
		for(int i=3;i<=N;i++){
            f[i] = (prev + f[i-1] + f[i-2] + 2 * f[i-3]) % MOD;
            prev = (prev + f[i-3] * 2) % MOD;
		}
		return f[N];
    }
};

int main(){
	Solution s;
	for(int i=2;i<10;i++)
		cout << i << ' ' << s.numTilings(i) << endl;
}