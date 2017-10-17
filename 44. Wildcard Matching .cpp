#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	vector< vector<bool> > DP, found;
	int N, M;

	bool isMatch(const string& s,const string& p, int sIndex, int pIndex) {
		if(sIndex == N && pIndex == M)
			return true;

		if(sIndex == N){
			if(p[pIndex] == '*')
				return isMatch(s, p, sIndex, pIndex+1);
			return false;
		}

		if(pIndex == M)
			return false;

		if(found[sIndex][pIndex])
			return DP[sIndex][pIndex];

		char sChar = s[sIndex], pChar = p[pIndex];
		bool res = false;
		if(sChar == pChar || pChar == '?')
			res |= isMatch(s, p, sIndex+1, pIndex+1);
		else if(pChar == '*'){
			res |= isMatch(s, p, sIndex, pIndex+1);
			res |= isMatch(s, p, sIndex+1, pIndex);
			res |= isMatch(s, p, sIndex+1, pIndex+1);
		}

		found[sIndex][pIndex] = true;
		DP[sIndex][pIndex] = res;
		return res;
    }
public:
    bool isMatch(string s, string p) {
    	N = s.size();
    	M = p.size();
    	DP = vector< vector<bool> >(N, vector<bool>(M, false));
    	found = vector< vector<bool> >(N, vector<bool>(M, false));
    	return isMatch(s, p, 0, 0);
    }
};

int main(){
	Solution s;
	cout << s.isMatch("abbabbbaabaaabbbbbabbabbabbbabbaaabbbababbabaaabbab", "*aabb***aa**a******aa*") << endl;
	cout << s.isMatch("", "**") << endl;
	cout << s.isMatch("", "**?") << endl;
	cout << s.isMatch("aa", "a") << endl;
	cout << s.isMatch("aa", "aa") << endl;
	cout << s.isMatch("aa", "a?") << endl;
	cout << s.isMatch("aab", "a*") << endl;
	cout << s.isMatch("axaxa", "a?xa") << endl;
	cout << s.isMatch("axaxa", "a*xa") << endl;
	cout << s.isMatch("axaxa", "ax?xa") << endl;
}