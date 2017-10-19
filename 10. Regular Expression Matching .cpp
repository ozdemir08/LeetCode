#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	string s, p;
	int sLen, pLen;
	vector< vector<bool> > visited, DP;

bool isMatch(int sIndex, int pIndex){
	// string finished
	if(sIndex == sLen){
		// pattern also finished
		if(pIndex == pLen)
			return true;

		// if a char without a star
		if((pLen - pIndex) % 2 == 1)
			return false;

		// if pattern has also chars with stars left
		for(int i=pIndex+1;i<pLen;i+=2)
			if(p[i] != '*')
				return false;
		return true;
	}
	// pattern finished but str not
	if(pIndex == pLen)
		return false;

	if(visited[sIndex][pIndex])
		return DP[sIndex][pIndex];

	bool res = false;
	if(p[pIndex] == '.'){
		if(pIndex < pLen -1 && p[pIndex + 1] == '*'){
			// use star
			res |= isMatch(sIndex + 1, pIndex);
			// do not use star
			res |= isMatch(sIndex, pIndex + 2);
		}
		else
			res = isMatch(sIndex + 1, pIndex + 1);
	}
	// eg: pat : ..a*.. 
	else if(pIndex < pLen - 1 && p[pIndex + 1] == '*'){
		// eg: str: ..aaa.. , ..a..
		if(s[sIndex] == p[pIndex])
			res = isMatch(sIndex + 1, pIndex);
		// eg: str: bbb
		res |= isMatch(sIndex, pIndex + 2);
	}
	else if(s[sIndex] == p[pIndex])
		res = isMatch(sIndex + 1, pIndex + 1);

	visited[sIndex][pIndex] = true;
	DP[sIndex][pIndex] = res;
	return res;
}

public:
    bool isMatch(string str, string pattern) {
        s = str; 
        p = pattern;
        sLen = s.size();
        pLen = p.size();
        visited = vector< vector<bool> >(sLen, vector<bool>(pLen, false));
        DP = vector< vector<bool> >(sLen, vector<bool>(pLen, false));

        return isMatch(0, 0);
    }
};

int main(){
	Solution s;
	cout << s.isMatch("aaa", "a*a") << endl;
}