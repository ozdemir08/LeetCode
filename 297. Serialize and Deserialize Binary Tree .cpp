#include <iostream>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
private:
    
    static string intToString(int num){
        string res = "";
        do{
            res += num % 10 + '0';
            num /= 10;
        }while(num);
        reverse(res.begin(), res.end());
        return res;
    }
    
    static int stringToInt(string num){
        int res = 0;
        for(int i=0;i<num.size();i++)
            res = 10 * res + num[i] - '0';
        return res;
    }

    static string subdata(string data, int beginIndex){
        char c = data[beginIndex];
        string subData(1, c);

        int paranthesis = 1;
        int i = beginIndex + 1;
        while(paranthesis > 0){
            subData += data[i];
            if(data[i] == '{')
                paranthesis ++;
            else if(data[i] == '}')
                paranthesis --;
            i++;
        }
        return subData;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "{}";
        
        string serialized = "{";
        serialized += intToString(root -> val);
        serialized += ",";
        serialized += serialize(root -> left);
        serialized += ",";
        serialized += serialize(root -> right);
        serialized += "}";
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[1] == '}')
            return NULL;
        int commaIndex = data.find(',');
        string val = data.substr(1, commaIndex - 1);
        TreeNode* root = new TreeNode(stringToInt(val));

        string leftData = subdata(data, commaIndex + 1);
        root -> left = deserialize(leftData);

        string rightData = subdata(data, commaIndex + 1 + leftData.size() + 1);
        root -> right = deserialize(rightData);
    
        return root;
    }
};


int main(){
    TreeNode *root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> right -> left = new TreeNode(4);
    root -> right -> right = new TreeNode(5);
    root -> right -> right -> right = new TreeNode(6);
    Codec codec;
    cout << codec.serialize(root) << endl;
    codec.deserialize(codec.serialize(root));
}