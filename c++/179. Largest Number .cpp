#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {

private:
    static string intToString(int num){
        string res = "";
        do{
            res += num%10 + '0';
            num /= 10;
        }while(num);
        reverse(res.begin(), res.end());
        return res;
    }

    static bool cmp(int a, int b){
        string num1 = intToString(a);
        string num2 = intToString(b);

        return num1 + num2 > num2 + num1;
    }
    
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        if(nums[0] == 0)
            return "0";
            
        string res = "";
        
        for(int i=0;i<nums.size();i++)
            res += intToString(nums[i]);
        return res;
    }

};

int main(){
    vector<int> v;
    v.clear();
    for(int i=0;i<40;i++)
        v.push_back(0);
    Solution s;
    cout << s.largestNumber(v) << endl;
}