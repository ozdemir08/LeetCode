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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *node1 = l1, *node2 = l2, *head = NULL, *tail = NULL;
        while(node1 || node2){
            
            int val = carry;
            if(node1){
                val += node1 -> val;
                node1 = node1 -> next;
            
            }
            if(node2){
                val += node2 -> val;
                node2 = node2 -> next;
            
            }
            carry = val/10;
            ListNode *newNode = new ListNode(val%10);
            if(!head){
                head = tail = newNode;
            }
            else{
                tail -> next = newNode;
                tail = newNode;
            }
        }
        if(carry){
            tail -> next = new ListNode(1);
            tail = tail -> next;
        }
        return head;
    }
};