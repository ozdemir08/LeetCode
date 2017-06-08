#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

class Solution {

public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode *head = NULL, *tail = NULL; 
        vector< pair<int, int> > V;
        make_heap(V.begin(), V.end(), cmp);

        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                V.push_back(make_pair(lists[i] -> val, i));
                lists[i] = lists[i] -> next;
                push_heap(V.begin(), V.end(), cmp);
            }
        }
        int i = 0;
        while(!V.empty()){
            
            pair<int, int> cur = V[0];
            pop_heap(V.begin(), V.end(), cmp);
            V.pop_back();
            if(lists[cur.second]){
                V.push_back(make_pair(lists[cur.second] -> val, cur.second));
                lists[cur.second] = lists[cur.second] -> next;
                push_heap(V.begin(), V.end(), cmp);
            }
            
            ListNode *next = new ListNode(cur.first);
            if(!head)
                head = tail = next;
            else{
                tail -> next = next;
                tail = next;
            }
        }
        return head;
    }

};

int main(){
    Solution s;
    std::vector<ListNode*> v;
    for(int i=0;i<10;i++){
        ListNode *head, *tail;
        head = tail = new ListNode(10*i);
        for(int j=1;j<10;j++){
            ListNode *next = new ListNode(10*i+j);
            tail -> next = next;
            tail = next;
        }
        v.push_back(head);
    }
    ListNode *merged = s.mergeKLists(v);
    while(merged){
        cout << merged -> val << ' ';
        merged = merged -> next;   
    }
}