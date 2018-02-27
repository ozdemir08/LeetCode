#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string text, vector<string>& words) {
		int N = text.size();
		int M = words.size();
		if(!M)
			return vector<int>();
		int K = words[0].size();
		// vector -> unordered_set
		unordered_set<string> dict;
		for(int i=0;i<words.size();i++)
			dict.insert(words[i]);

		// result indices
		vector<int> res;

		// begin from 0, 1, … K - 1
		for(int i=0;i<K;i++){
			unordered_set<string> remainings;
			for(auto &it : dict)
				remainings.insert(it);
			queue<string> q;

			for(int j=i;j+K<N;j+=K){
				string cur = text.substr(j, K);
			/**
				There are now 3 cases.
				1. cur is not in dict
				2. cur is in dict but not in remainings
				3. cur is in dict and in remainings
			*/
			// first case: cur is not in dict
				if(dict.find(cur) == dict.end()){
					while(!q.empty()){
						string word = q.front();
						q.pop();
						remainings.insert(word);
					}
				}
			// second case: in dict but not in remainings
				else if(remainings.find(cur) == remainings.end()){
					while(!q.empty()){
						string word = q.front();
						q.pop();
						if(word == cur){
							q.push(cur);
							break;
						}
						remainings.insert(word);
					}
				}
			// third case: in dict and in remainings
				else{
					remainings.erase(cur);
					q.push(cur);
					if(remainings.empty()){
						res.push_back(j-(M-1)*K);
						string word = q.front();
						q.pop();
						remainings.insert(word);
					}
				}
			}
		}
		return res;
	}
};

int main(){
	string text = "barfoofoobarthefoobarman";
	vector<string> dict;
	dict.push_back("foo");
	dict.push_back("bar");
	dict.push_back("the");
	Solution s;
	vector<int> v = s.findSubstring(text, dict);
	for(int i=0;i<v.size();i++)
		cout << v[i] << endl;
}

