#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int T[255] = {};
        bool H[255] = {};
        int nonzeros = t.size();
        int ml = -1, mr = s.size();
        for(int i=0;i<t.size();i++){
            T[t[i]] ++;
            H[t[i]] = true;
        }
        int l = 0;

        for(int i=l;i<s.size();i++){
            char c = s[i];
            if(!H[c]) continue;
            T[c] --;

            if(T[c] >= 0)
                nonzeros--;

            if(!nonzeros){
                while(!nonzeros) {
                    if(!H[s[l]]) {l++;continue;}
                    T[s[l]] ++;
                    if(T[s[l]] > 0)
                        nonzeros++;
                    l++;
                }
                if(mr - ml > i - l + 1){
                    mr = i;
                    ml = l - 1;
                }
            }
        }
        return ml == -1 ? "" : s.substr(ml, mr-ml+1);
    }
};

int main(){
    Solution s;
    string s1, s2;
    cin >> s1 >> s2;
    cout << s.minWindow(s1, s2) << endl;
}