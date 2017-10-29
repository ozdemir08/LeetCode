class Solution {
private:
	const long long MOD = 1000000007;
public:
    int kInversePairs(int N, int K) {

    	vector< vector<long long> > DP(K+2, (vector<long long>(N+2, 0)));
    	vector< vector<long long> > sum(K+2, (vector<long long>(N+2, 0)));
    	for(int j=0;j<N;j++){
    		DP[0][j] = 1;
    		sum[0][j] = 1;
    	}

    	for(int i=1;i<=K;i++)
    		for(int j=N-1;j>=0;j--){
    			DP[i][j] = sum[i][j+1];
    			int r = N - j - 1;
    			if(i-r-1>=0)
    				DP[i][j] = (DP[i][j] - sum[i-r-1][j+1] + MOD) % MOD;
    			sum[i][j] = (sum[i-1][j] + DP[i][j] + MOD) % MOD;
    		}

        return DP[K][0];   
    }
};

class Solution2 {
private:
	const static long long MOD = 1000000007;
public:
    int kInversePairs(int N, int K) {

    	vector< vector<long long> > sum(K+2, (vector<long long>(N+2, 0)));
    	for(int j=0;j<N;j++){
    		sum[0][j] = 1;
    	}

    	for(int i=1;i<=K;i++)
    		for(int j=N-1;j>=0;j--){
    			long long temp = sum[i][j+1];
    			int r = N-j-1;
    			if(i-r-1>=0)
    				temp = (temp - sum[i-r-1][j+1] + MOD) % MOD;
    			sum[i][j] = (sum[i-1][j] + temp + MOD) % MOD;
    		}

        return (sum[K][0] - (!K ? 0 : sum[K-1][0]) + MOD) % MOD;   
    }
};