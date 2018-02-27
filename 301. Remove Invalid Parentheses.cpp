#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		vector<string> res;
		vector< set<string> > visited(s.length()+1, set<string>());
		dfs(s, 0, "", res, 0, visited);
		int differentCases = 0;
		for(int i=0;i<s.length()+1;i++)
			differentCases += visited[i].size();
		cout << differentCases << endl;
		return res;
	}
	void dfs(string& s, int pos, string cur, vector<string>& res, int dif, vector< set<string> >& visited){
		// to prevent duplicates
		if(visited[pos].find(cur) != visited[pos].end())
			return;
		visited[pos].insert(cur);

        // base case
		if(pos == s.length()){
			if(dif != 0)
				return;
			if(!res.empty()){
				if(res[0].length() < cur.length())
					res.clear();
				else if(res[0].length() > cur.length()){
					return;
				}
			}
			res.push_back(cur);
			return;
		}
	    // check if longer string is not possible
		if(!res.empty() && res[0].length() > cur.length() + s.length() - pos)
			return;

        char c = s[pos];
        // non-paranthesis character
		if(c != '(' && c != ')'){
			dfs(s, pos+1, cur+c, res, dif, visited);
			return;
		}

        // add '(' and ')'
		if(c == '(' || dif > 0){
			int d_dif = ((c == '(') ? 1: -1);
			dfs(s, pos+1, cur+c, res, dif+d_dif, visited);
		}
        // skip to next
		dfs(s, pos+1, cur, res, dif, visited);
	}
};

int main(){
	string s = "()())()())";
	Solution se;
	vector<string> v = se.removeInvalidParentheses(s);
	cout << v.size() << endl;
	// for(int i=0;i<v.size();i++)
	// 	cout << v[i] << endl;
}