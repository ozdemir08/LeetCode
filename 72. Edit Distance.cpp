#include <iostream>
#include <string>

using namespace std;



class Solution {
public:
    int minDistance(string word1, string word2) {
    	int DP[1000][1000] = {};
        int N = word1.size(), M = word2.size();
    	for(int i=1;i<=N;i++) DP[i][0] = i;
    	for(int j=1;j<=M;j++) DP[0][j] = j;	
        for (int i=1;i<=N;i++)
        	for(int j=1;j<=M;j++)
        		if(word1[i-1] == word2[j-1])
        			DP[i][j] = DP[i-1][j-1];
        		else
        			DP[i][j] = 1 + min(DP[i-1][j], min(DP[i][j-1], DP[i-1][j-1]));
        return DP[N][M];
    }
};

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	Solution s;
	cout << s.minDistance(s1, s2) << endl;
}
