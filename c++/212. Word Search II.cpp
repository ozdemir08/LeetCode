#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
public:
	bool isWord;
	bool isAdded;
	TrieNode *children[26];
	TrieNode(){
		isWord = isAdded = false;
        for(int i=0;i<26;i++)
            children[i] = NULL;
	}
};

class Trie{

public:
	TrieNode *root;
	Trie(vector<string>& words){
		root = new TrieNode();
		for(int i=0;i<words.size();i++)
			insert(words[i]);
	}

	void insert(string s){
		TrieNode *node = root;
		int n = s.size();
		for(int i=0;i<n;i++){
			int ind = s[i] - 'a';
			if(node -> children[ind] == NULL)
				node -> children[ind] = new TrieNode();
			node = node -> children[ind];
		}
		node -> isWord = true;
	}
};

class Solution {
private:
	// Error in my pc! WHY?
	int dir[4][2]{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	// ---- ---
	int n, m;
	vector< vector<bool> > visited;

	void dfs(TrieNode *node, int i, int j, string s, vector<vector<char> >& board, vector<string>& res){
		visited[i][j] = true;

		if(node -> isWord && node -> isAdded == false){
			res.push_back(s);
			node -> isAdded = true;
		}

		for(int y=0;y<4;y++){
			int ni = i + dir[y][0], nj = j + dir[y][1];
			if(ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj]){
				char c = board[ni][nj];
				if(node -> children[c-'a']){
					dfs(node -> children[c-'a'], ni, nj, s + c, board, res);
				}
			}
		}

		visited[i][j] = false;
	}

public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {

    	// empty board
    	if(board.empty())
    		return vector<string>();

		// add words to trie
    	Trie trie(words); 
    	vector<string> res;

        n = board.size();
        m = board[0].size();
        visited = vector< vector<bool> >(n, vector<bool>(m, false));

        // travel on board and trie, as long as node is not null
        TrieNode *root = trie.root;
        for(int i=0;i<n;i++)
        	for(int j=0;j<m;j++){
        		char c = board[i][j];
        		if(root -> children[c - 'a']){
                    string s = "";
        			dfs(root -> children[c - 'a'], i, j, s + c, board, res);
                }
        	}
        return res;
    }
};

int main(){
	vector<vector<char> > board(2, vector<char>(2, 'a'));
	board[0][1] = 'b';
	vector<string> words;
	words.push_back("aba");
	words.push_back("baa");
	words.push_back("bab");
	words.push_back("aaab");
	words.push_back("aaa");
	words.push_back("aaaa");
	words.push_back("aaba");
	Solution s;
	s.findWords(board, words);

}