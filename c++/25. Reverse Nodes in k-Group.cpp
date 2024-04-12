#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode *next = head;
        while(n < k && next){
            n++;
            next = next -> next;
        }
        if(n < k)
            return head;

        ListNode *slow = head, *fast = head -> next;
        for(int i=1;i<k;i++){
            ListNode *tmp = fast -> next;
            fast -> next = slow;
            slow = fast;
            fast = tmp;
        }
        head -> next = reverseKGroup(next,k);
        return slow;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(0);
    ListNode *curr = head;
    for(int i=1;i<=9;i++){
        curr -> next = new ListNode(i);
        curr = curr -> next;
    }

    Solution s;
    ListNode *tmp = s.reverseKGroup(head, 1);
    while(tmp){
        cout << tmp -> val << endl;
        tmp = tmp -> next;
    }
    return 0;
}