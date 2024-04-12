#include <iostream>

using namespace std;

class Node {
public:
    bool isEnd;
    Node *children[26];
    
    Node(){
        isEnd = false;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Node *root;
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        
        for(int i=0;i<word.size();i++){
            int letter = word[i] - 'a';
            if(!node -> children[letter])
                node -> children[letter] = new Node();
            node = node -> children[letter];
        }
        node -> isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *node = root;

        for(int i=0;i<word.size();i++){
            int letter = word[i] - 'a';
            node = node -> children[letter];
            if(!node)
                return false;
        }
        return node -> isEnd;            
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *node = root;

        for(int i=0;i<prefix.size();i++){
            int letter = prefix[i] - 'a';
            node = node -> children[letter];
            if(!node)
                return false;
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main(){
    string s = "mehmet";
    Trie obj;

    obj.insert(s);

    cout << obj.search("meh") << endl;
    cout << obj.search("mehmet") << endl;
    cout << obj.startsWith("mehm") << endl;
}