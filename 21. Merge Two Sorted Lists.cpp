/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *tail = NULL;

        while(l1 != NULL || l2 != NULL){
            int valToAdd;
            if(l1 != NULL && (l2 == NULL || l1 -> val < l2 -> val)){
                valToAdd = l1 -> val;
                l1 = l1 -> next;
            }
            else{
                valToAdd = l2 -> val;
                l2 = l2 -> next;
            }
            if(!head)
                head = tail = new ListNode(valToAdd);
            else{
                tail -> next = new ListNode(valToAdd);
                tail = tail -> next;
            }
        }
        return head;
    }
};