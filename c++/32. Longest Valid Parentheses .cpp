#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector< pair<int,int> > v[2];
        v[0].clear();
        v[1].clear();
        int n = s.size();
        for(int i=0;i<n-1;i++){
            if(s[i] == '(' && s[i+1] == ')'){
                v[0].push_back(make_pair(i, i+1));
                i++;
            }
        }
        bool isChanged = true;
        int cur = 0, mx = 0, nxt;
        while(isChanged){
            
            cout << "____" << endl;
            isChanged = false;
            nxt = 1 - cur;
            
            for(int j=0;j<v[cur].size();j++){
            	cout << v[cur][j].first << ' ' << v[cur][j].second << endl;
            	mx = max(mx, v[cur][j].second - v[cur][j].first + 1);
                if(j<v[cur].size()-1 && v[cur][j].second + 1 == v[cur][j+1].first){
                    v[nxt].push_back(make_pair(v[cur][j].first, v[cur][j+1].second));
                    isChanged = true;
                    j++;
                }
                else if(v[cur][j].first-1 >= 0 && v[cur][j].second+1 <s.size() && s[v[cur][j].first-1] == '(' && s[v[cur][j].second+1] == ')'){
                    v[nxt].push_back(make_pair(v[cur][j].first-1, v[cur][j].second+1));
                    isChanged = true;
                }
                else{
                	v[nxt].push_back(v[cur][j]);
                }
            }
            v[cur].clear();
            cur = 1 - cur;
        }
        return mx;
    }
};

int main(){
	Solution s;
	cout << s.longestValidParentheses(")(((((()())()()))()(()))(") << endl;
}